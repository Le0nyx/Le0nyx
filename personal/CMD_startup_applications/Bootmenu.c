/*
File: newBootFile.c
Date: 29-07-2024  19:30
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define MAX_REPOS 10
#define MAX_URL_LENGTH 256
#define MAX_PATH_LENGTH 256

void clone_repos(char repos[MAX_REPOS][MAX_URL_LENGTH], int repo_count, char *dest_folder);
void turnOnLog();
void discordBot();
void staticIPConfig();

int main() {
    //making UI

    printf("\n--------------------------------------");
    printf("\n [1] Games");
    printf("\n [2] Backup Git");
    printf("\n [3] Discord Bot");
    printf("\n [4] Log Boot");
    printf("\n [5] Static IP Config");
    printf("\n [6] Only upload Arduino");
    printf("\n\n [else] Exit");

    printf("\n\n -------------------------------------- \n\n");

    int choice = 0;
    printf("\n\n Choose a mode to start: ");
    scanf("%d", &choice);

    sleep(1);
    
    chdir("#######");

    switch (choice){
    case 1: //games
        system("start ####");
		system("start ####");
        system("start ####");

        break;

    case 2: //backup git
        system("cls");
		char repos[MAX_REPOS][MAX_URL_LENGTH];
		char dest_folder[MAX_PATH_LENGTH];
		int repo_count = 0;

		strcpy(dest_folder, "####");


		strcpy(repos[0], "####");
		strcpy(repos[1], "####");
		strcpy(repos[2], "####");

		repo_count = 3;

		clone_repos(repos, repo_count, dest_folder);
        break;
    
    case 3: //discord bot
        discordBot();
        break;

    case 4: //log boot
        turnOnLog();
        break;

    case 5: //static ip config
        staticIPConfig();
        break;

    case 6: //only upload arduino
        system("start arduino_upload.exe");
        break;
    default:
        printf("\n Ending Code");
        return 0;
        break;
    }

    return 0;
}




void turnOnLog() {
    chdir("####");
    system("start turnOnLog.exe");
}

void discordBot() {
    chdir("####");
    system("python updated-standalone-discord-bot.py");
    system(" ");
}

void staticIPConfig() {
    chdir("####");
    system("start runas /user:Administrator staticIPConfig.exe");
}


// Function to clone repositories from a list of URLs
void clone_repos(char repos[MAX_REPOS][MAX_URL_LENGTH], int repo_count, char *dest_folder){
    char command[MAX_PATH_LENGTH + MAX_URL_LENGTH + 50];
    char repo_name[MAX_PATH_LENGTH];
    char new_repo_path[MAX_PATH_LENGTH];
    char original_repo_path[MAX_PATH_LENGTH];

    // Create and change to the destination directory
    snprintf(command, sizeof(command), "mkdir -p %s", dest_folder);
    system(command);
    snprintf(command, sizeof(command), "cd %s", dest_folder);
    system(command);

    for (int i = 0; i < repo_count; i++) {
        // Extract the repository name from the URL
        snprintf(repo_name, sizeof(repo_name), "%s", strrchr(repos[i], '/') + 1);
        // Remove the .git suffix if present
        if (strstr(repo_name, ".git") != NULL) { repo_name[strlen(repo_name) - 4] = '\0'; }
        // Paths for new and original repositories
        snprintf(new_repo_path, sizeof(new_repo_path), "%s/new_%s", dest_folder, repo_name);
        snprintf(original_repo_path, sizeof(original_repo_path), "%s/%s", dest_folder, repo_name);
        // Clone the repository into a temporary directory
        snprintf(command, sizeof(command), "git clone %s %s", repos[i], new_repo_path);
        printf("Executing: %s\n", command);
        system(command);
        // Use rsync to copy only new or modified files
        snprintf(command, sizeof(command), "rsync -av --ignore-existing %s/ %s/", new_repo_path, original_repo_path);
        printf("Executing: %s\n", command);
        system(command);
        // Clean up the temporary cloned repository
        snprintf(command, sizeof(command), "rm -rf %s", new_repo_path);
        printf("Executing: %s\n", command);
        system(command);
    }
}

