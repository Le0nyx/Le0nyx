#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int event_loop = 1; // Variable to define loop

#define BUFFER_PROCESSED_INPUT 50

void end_event_loop()
{
    event_loop = 0;
}

void start_menu()
{
    // clrscr();
    printf("Shelly, Herald of the Rift\n");
    printf("Version 1.0\n");
    printf("By Juls, aLeg, iVan and Schle\n");
    printf("Usable Commands: touch, ls, rm, mkdir, sl, echo, whoami, cat (ADD COMMANDS HERE)\n");
}

void userbar()
{
    printf("\nShelly@User >");
}

void strtrim(char *string)
{
    string[strlen(string) - 1] = '\0';
}

void clrscr()
{
    system("clear");
}

void no_known_command(char *user_Input)
{
    printf("%s not known\n", user_Input);
}

void touch(char *user_Input)
{
    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    for (int i = 6; i <= strlen(user_Input); i++)
    {
        processed_user_Input[i - 6] = user_Input[i];
    }
    FILE *fp;
    fp = fopen(processed_user_Input, "w");
    fclose(fp);
}

void sl()
{
    int pid = fork();
    if (pid == -1)
    {
        perror("forking");
    }
    else if (!pid)
    {
        execl("/opt/homebrew/Cellar/sl/5.02/bin/sl", "/opt/homebrew/Cellar/sl/5.02/bin/sl", NULL);
    }
    else
    {
        wait(NULL);
    }
}

void cat(char *user_Input)
{
    char c;

    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    for (int i = 4; i <= strlen(user_Input); i++)
    {
        processed_user_Input[i - 4] = user_Input[i];
    }

    FILE *fp;
    fp = fopen(processed_user_Input, "r");

    if (fp == NULL)
    {
        printf("Shelly can`t read this file");
    }
    c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    printf("\n");
}

void mkdir(char *user_Input)
{
    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    int pid = fork();
    for (int i = 6; i <= strlen(user_Input); i++)
    {
        processed_user_Input[i - 6] = user_Input[i];
    }
    if (!pid)
    {
        execl("/bin/mkdir", "mkdir", processed_user_Input, NULL);
    }
}

void ls(char *user_Input)
{

    int pid = fork();
    if (!pid)
    {
        if (strlen(user_Input) == 2)
        {
            execl("/bin/ls", "/bin/ls", NULL);
        }
        else if (strlen(user_Input) == 5)
        {
            char arg1[3];
            for (int i = 0; i < 2; i++)
            {
                arg1[i] = user_Input[i + 3];
            }
            execl("/bin/ls", "/bin/ls", arg1, NULL);
        }
        else if (strlen(user_Input) == 6)
        {
            char arg1[3];
            char arg2[3] = {'-',
                            '-',
                            '\0'};

            for (int i = 0; i < 2; i++)
            {
                arg1[i] = user_Input[i + 3];
                arg2[i + 1] = user_Input[i + 5];
            }
            arg1[2] = '\0';
            arg2[2] = '\0';
            execl("/bin/ls", "/bin/ls", arg1, arg2, NULL);
        }
        else
        {
            char arg1[3];
            char arg2[3];

            for (int i = 0; i < 2; i++)
            {
                arg1[i] = user_Input[i + 3];
                arg2[i] = user_Input[i + 6];
            }
            arg1[2] = '\0';
            arg2[2] = '\0';

            execl("/bin/ls", "/bin/ls", arg1, arg2, NULL);
        }
    }
    else
    {
        wait(NULL);
    }
}

void rm(char *user_Input)
{
    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    int pid = fork();
    for (int i = 3; i <= strlen(user_Input); i++)
    {
        processed_user_Input[i - 3] = user_Input[i];
    }
    if (!pid)
    {
        execl("/bin/rm", "rm", processed_user_Input, NULL);
    }
}

void rmr(char *user_Input)
{
    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    int pid = fork();
    for (int i = 6; i <= strlen(user_Input); i++)
    {
        processed_user_Input[i - 6] = user_Input[i];
    }
    if (!pid)
    {
        execl("/bin/rm", "/bin/rm", "-r", processed_user_Input, NULL);
    }
}

void echo(char *user_Input)
{
    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    for (int i = 5; i <= strlen(user_Input); i++)
    {
        processed_user_Input[i - 5] = user_Input[i];
    }

    printf("%s\n", processed_user_Input);
}

void whoami()
{
    printf("\nI am the great Sir George William Washington Herald of the Rift the third. \nFound in the top jungle of the summoners rift, in the baron pit after 7 minutes have passed and before 20 minutes.");
}

void cd(char *user_Input)
{
    char processed_user_Input[BUFFER_PROCESSED_INPUT];
    for (int i = 3; i < strlen(user_Input); i++)
    {
        processed_user_Input[i - 3] = user_Input[i];
    }
    if (chdir(processed_user_Input) != 0)
        perror("chdir()failed");
}

void get_command()
{
    int max_userinput = 100;

    char user_Input[max_userinput];
    fflush(stdin);
    fgets(user_Input, max_userinput, stdin);
    strtrim(user_Input);
    if (user_Input[0] == 't' && user_Input[1] == 'o' && user_Input[2] == 'u' && user_Input[3] == 'c' && user_Input[4] == 'h' && user_Input[5] == ' ')
    {
        touch(user_Input);
    }
    else if (user_Input[0] == 'l' && user_Input[1] == 's')
    {
        ls(user_Input);
    }
    else if (user_Input[0] == 's' && user_Input[1] == 'l')
    {
        sl();
    }
    else if (user_Input[0] == 'c' && user_Input[1] == 'a' && user_Input[2] == 't' && user_Input[3] == ' ')
    {
        cat(user_Input);
    }
    else if (user_Input[0] == 'm' && user_Input[1] == 'k' && user_Input[2] == 'd' && user_Input[3] == 'i' && user_Input[4] == 'r' && user_Input[5] == ' ')
    {
        mkdir(user_Input);
    }
    else if (user_Input[0] == 'r' && user_Input[1] == 'm' && user_Input[2] == ' ' && user_Input[3] == '-' && user_Input[4] == 'r' && user_Input[5] == ' ')
    {
        rmr(user_Input);
    }
    else if (user_Input[0] == 'r' && user_Input[1] == 'm' && user_Input[2] == ' ')
    {
        rm(user_Input);
    }
    else if (user_Input[0] == 'e' && user_Input[1] == 'c' && user_Input[2] == 'h' && user_Input[3] == 'o' && user_Input[4] == ' ')
    {
        echo(user_Input);
    }
    else if (user_Input[0] == 'w')
    {
        whoami();
    }
    else if (user_Input[0] == 'c' && user_Input[1] == 'd' && user_Input[2] == ' ')
    {
        cd(user_Input);
    }
    else
    {
        no_known_command(user_Input);
    }
}

int main()
{
    signal(SIGINT, end_event_loop);

    start_menu();
    while (event_loop)
    {
        userbar();
        get_command();
    }

    return EXIT_SUCCESS;
}
