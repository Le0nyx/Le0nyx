// subserver_win.c
// Simple SubServer for MainServer (Windows / Winsock).
// Usage: subserver_win.exe [name]
// It registers commands: time, date, calc, filelist
// When receiving lines "EXEC <cmdline> FROM <user>" responds with single-line answers.

// gcc -o subserver_win.exe subserver.c -lws2_32; if ($LASTEXITCODE -eq 0) { .\subserver_win.exe }

#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_WINNT 0x0601
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>  // for _kbhit()

#pragma comment(lib, "ws2_32.lib")

#define MAIN_HOST "127.0.0.1"
#define MAIN_PORT "8888"
#define BUFSIZE 4096

static SOCKET sock = INVALID_SOCKET;

int send_raw(const char *s) {
    if (!s) return -1;
    int len = (int)strlen(s);
    int sent = 0;
    while (sent < len) {
        int r = send(sock, s + sent, len - sent, 0);
        if (r == SOCKET_ERROR) return -1;
        sent += r;
    }
    return 0;
}

int send_line(const char *s) {
    if (send_raw(s) != 0) return -1;
    if (send(sock, "\n", 1, 0) == SOCKET_ERROR) return -1;
    return 0;
}

void handle_exec_command(const char *cmdline, int interactive) {
    if (strncmp(cmdline, "/time", 5) == 0) {
        char out[128];
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(out, sizeof(out), "%H:%M:%S", tm);
        if (interactive) {
            printf("Current time: %s\n", out);
        } else {
            strcat(out, "\n");
            send_raw(out);
        }
    } else if (strncmp(cmdline, "/date", 5) == 0) {
        char out[128];
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(out, sizeof(out), "%Y-%m-%d", tm);
        if (interactive) {
            printf("Current date: %s\n", out);
        } else {
            strcat(out, "\n");
            send_raw(out);
        }
    } else if (strncmp(cmdline, "/calc", 5) == 0) {
        if (interactive) {
            printf("Calculator ready: CALC_OK\n");
        } else {
            send_line("CALC_OK");
        }
    } else if (strncmp(cmdline, "/filelist", 9) == 0) {
        if (interactive) {
            printf("Available files: sample1.txt, sample2.txt\n");
        } else {
            send_line("FILES sample1.txt,sample2.txt");
        }
    } else if (strncmp(cmdline, "/get", 4) == 0) {
        if (interactive) {
            printf("Get command ready: GET_OK\n");
        } else {
            send_line("GET_OK");
        }
    } else {
        if (interactive) {
            printf("Unknown command: %s\n", cmdline);
        } else {
            send_line("UNKNOWN");
        }
    }
}

int main(int argc, char **argv) {
    const char *name = (argc > 1) ? argv[1] : "ctimesrv";

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        fprintf(stderr, "WSAStartup failed\n");
        return 1;
    }

    struct addrinfo hints = {0}, *res = NULL;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(MAIN_HOST, MAIN_PORT, &hints, &res) != 0) {
        fprintf(stderr, "getaddrinfo failed\n");
        WSACleanup();
        return 1;
    }

    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == INVALID_SOCKET) { freeaddrinfo(res); WSACleanup(); return 1; }

    printf("Attempting to connect to MainServer at %s:%s...\n", MAIN_HOST, MAIN_PORT);
    
    if (connect(sock, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
        fprintf(stderr, "connect failed: %d\n", WSAGetLastError());
        fprintf(stderr, "Make sure MainServer is running on %s:%s\n", MAIN_HOST, MAIN_PORT);
        closesocket(sock); freeaddrinfo(res); WSACleanup(); return 1;
    }
    freeaddrinfo(res);
    
    printf("Connected to MainServer successfully!\n");

    // register
    char line[BUFSIZE];
    snprintf(line, sizeof(line), "/subregister %s\n", name);
    send_raw(line);
    send_raw("/registercmd time\n");
    send_raw("/registercmd date\n");
    send_raw("/registercmd calc\n");
    send_raw("/registercmd filelist\n");
    send_raw("/registercmd get\n");

    printf("SubServer '%s' registered. Type commands like /time, /date, /calc, /filelist, /get\n");
    printf("Or wait for EXEC commands from MainServer. Type 'quit' to exit.\n");

    // receive loop with interactive input
    char buf[BUFSIZE];
    char accum[BUFSIZE * 4]; accum[0]=0;
    
    // Set socket to non-blocking for interactive mode
    u_long mode = 1;
    ioctlsocket(sock, FIONBIO, &mode);
    
    while (1) {
        // Check for keyboard input
        if (_kbhit()) {
            char input[256];
            if (fgets(input, sizeof(input), stdin)) {
                input[strcspn(input, "\r\n")] = 0; // remove newline
                if (strcmp(input, "quit") == 0) {
                    break;
                }
                if (input[0] == '/') {
                    printf("Executing: %s\n", input);
                    handle_exec_command(input, 1); // 1 = interactive mode
                }
            }
        }
        
        // Check for server messages
        int r = recv(sock, buf, sizeof(buf)-1, 0);
        if (r == SOCKET_ERROR) {
            int err = WSAGetLastError();
            if (err != WSAEWOULDBLOCK) break; // Real error
            Sleep(50); // Small delay to prevent busy waiting
            continue;
        }
        if (r == 0) break; // Connection closed
        if (r > 0) {
            buf[r] = 0;
            strncat(accum, buf, sizeof(accum)-strlen(accum)-1);
            char *nl;
            while ((nl = strchr(accum, '\n')) != NULL) {
                *nl = 0;
                // trim CR
                char *end = nl - 1;
                if (end >= accum && *end == '\r') *end = 0;
                // each line may contain messages like "EXEC <cmdline> FROM <user>" or other lines
                printf("[MAIN] %s\n", accum);
                if (strncmp(accum, "EXEC ", 5) == 0) {
                    const char *payload = accum + 5;
                    // payload might be "<cmdline> FROM <user>" - strip trailing " FROM ..." if present
                    char *frompos = strstr((char*)payload, " FROM ");
                    char cmdcopy[BUFSIZE];
                    if (frompos) {
                        size_t len = (size_t)(frompos - payload);
                        if (len >= sizeof(cmdcopy)) len = sizeof(cmdcopy)-1;
                        strncpy(cmdcopy, payload, len);
                        cmdcopy[len] = 0;
                    } else {
                        strncpy(cmdcopy, payload, sizeof(cmdcopy)-1);
                        cmdcopy[sizeof(cmdcopy)-1] = 0;
                    }
                    // trim
                    char *s = cmdcopy;
                    while (*s == ' ') s++;
                    handle_exec_command(s, 0); // 0 = network mode
                }
                // shift remainder
                size_t remaining = strlen(nl + 1);
                memmove(accum, nl + 1, remaining + 1);
            }
        }
    }

    printf("Disconnected from MainServer\n");
    closesocket(sock);
    WSACleanup();
    return 0;
}
