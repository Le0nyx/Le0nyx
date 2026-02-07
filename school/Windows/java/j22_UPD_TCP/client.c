// client_win.c
// Simple interactive client for MainServer (Windows / Winsock).
// Usage: compile and run. Type commands like /auth <user> <pass>, /help, /quit, /msg, /filesrv, /send, etc.

// gcc -o client_win.exe client.c -lws2_32; if ($LASTEXITCODE -eq 0) { .\client_win.exe }

#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_WINNT 0x0601
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define SERVER_HOST "127.0.0.1"
#define SERVER_PORT "8888"
#define BUFSIZE 4096

static SOCKET sock = INVALID_SOCKET;
static volatile int running = 1;

unsigned __stdcall receiver_thread(void *arg) {
    char buf[BUFSIZE];
    char accum[BUFSIZE * 4]; accum[0] = 0;
    while (running) {
        int r = recv(sock, buf, sizeof(buf)-1, 0);
        if (r <= 0) break;
        buf[r] = 0;
        // accumulate and print full lines
        strncat(accum, buf, sizeof(accum)-strlen(accum)-1);
        char *nl;
        while ((nl = strchr(accum, '\n')) != NULL) {
            *nl = 0;
            // trim CR
            char *end = nl - 1;
            if (end >= accum && *end == '\r') *end = 0;
            printf("[SERVER] %s\n", accum);
            // shift remaining
            size_t remaining = strlen(nl + 1);
            memmove(accum, nl + 1, remaining + 1);
        }
    }
    running = 0;
    return 0;
}

int send_line(const char *line) {
    if (sock == INVALID_SOCKET) return -1;
    int len = (int)strlen(line);
    int sent = 0;
    while (sent < len) {
        int r = send(sock, line + sent, len - sent, 0);
        if (r == SOCKET_ERROR) return -1;
        sent += r;
    }
    // send newline
    if (send(sock, "\n", 1, 0) == SOCKET_ERROR) return -1;
    return 0;
}

int main(void) {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        fprintf(stderr, "WSAStartup failed\n");
        return 1;
    }

    struct addrinfo hints = {0}, *res = NULL;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(SERVER_HOST, SERVER_PORT, &hints, &res) != 0) {
        fprintf(stderr, "getaddrinfo failed\n");
        WSACleanup();
        return 1;
    }

    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == INVALID_SOCKET) { freeaddrinfo(res); WSACleanup(); return 1; }

    if (connect(sock, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
        fprintf(stderr, "connect failed: %d\n", WSAGetLastError());
        closesocket(sock); freeaddrinfo(res); WSACleanup(); return 1;
    }
    freeaddrinfo(res);

    printf("Connected to MainServer %s:%s\n", SERVER_HOST, SERVER_PORT);

    // start receiver thread
    unsigned threadID;
    HANDLE th = (HANDLE)_beginthreadex(NULL, 0, receiver_thread, NULL, 0, &threadID);
    if (!th) {
        fprintf(stderr, "failed to create receiver thread\n");
        closesocket(sock); WSACleanup(); return 1;
    }

    char line[BUFSIZE];
    while (running) {
        if (!fgets(line, sizeof(line), stdin)) break;
        // remove newline
        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        if (strcmp(line, "/quit") == 0) {
            send_line("/quit");
            break;
        }

        // forward exact text to server
        if (send_line(line) != 0) {
            fprintf(stderr, "send failed\n");
            break;
        }
    }

    running = 0;
    // wait for receiver thread to exit
    WaitForSingleObject(th, 2000);
    CloseHandle(th);

    closesocket(sock);
    WSACleanup();
    printf("Client exiting.\n");
    return 0;
}
