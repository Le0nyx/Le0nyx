#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ls(char *string)
{
    char *arg1;
    char *arg2;
    int pid = fork();

    while (pid == -1)
    {
        int pid = fork();
        printf("Error occured while trying to fork;");
    }

    if (pid == 0)
    {
        int j = 0;
        for (int i = 3; string[i] != ' '; i++)
        {

            arg1[j] = string[i];
            j++;
        }
        j = 0;

        for (int i = 6; string[i] != ' '; i++)
        {

            arg2[j] = string[i];
            j++;
        }
        printf("-\n");
        printf("%s\n", arg1);
        printf("%s\n", arg2);

        execl("/bin/ls", "/bin/ls", arg1, arg2, NULL);

        printf("Error occured executing\n");
        exit(0);
    }
}

int main()
{
    char *input = "ls -a -l";
    printf(" ");
    ls(input);
    return 0;
}