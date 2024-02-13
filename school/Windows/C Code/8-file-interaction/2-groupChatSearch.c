/*
File: 2-groupChatSearch.c
Date: 18-01-2024  08:01
Author: Leon A.
File Description: 

This Programm goes through an exported Whatsappchat that got saved in a txt and counts diffrent things from diffrent people.
It counts how many messages without any flag and with flags the following:
-d  how many symbols of a person
-s  how many emojis of a person
-h  most posted time

(Parameters: file.exe textloaction.txt person -d/-s/-h)
(tested with file: "groupchat2.txt")

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Unicls();
int countMessages(FILE *file_pointer, char* person);
int countSymbols(FILE *file_pointer, char* person);
int countEmojis(FILE *file_pointer, char* person);
int countTimePosted(FILE *file_pointer, char* person);


int main(int argc, char* argv[]){
    FILE *file_pointer;
    file_pointer = fopen(argv[1], "r");
    if(file_pointer == NULL){ //error handeling
        printf("\n Parameters: textloaction.txt -d/-s/-h\n If no second argument given just calculates amount of messages");
        printf("\n\n argv[1] = %s  Filepath given: %s", argv[1], argv[1]);
        printf("\n ERROR OCCURED OPENING FILE OR NO/WRONG ARGUMENT GIVEN\n");
        return 0;
    }
    Unicls();
    printf("\n Parameters: textloaction.txt -d/-s/-h\n");
    
    int nameCount = 0;
    char line[1000];
    char name[100][100] = {0};
    while(fgets(line, 1000, file_pointer) != NULL){ //reading out the names from the file
        if(line[0] == '[' && line[19] == ']'){
            int i = 21;
            char temp[100];
            int duplicate = 0;
            while((line[i] != ':') && (i<60)){
                temp[i-21] = line[i];
                i++;
            }
            temp[i-21] = '\0';
            for(int j = 0; j < nameCount; j++){
                if(strcmp(temp, name[j]) == 0){
                    duplicate = 1;
                    break;
                }
            }
            if(!duplicate){
                strcpy(name[nameCount], temp);
                nameCount++;
            }
        }
    }

    for(int i = 0;i<nameCount;i++){
        fseek(file_pointer, 0, SEEK_SET);
        if(argv[2] == NULL){
            printf("\n %s posted %d messages", name[i], countMessages(file_pointer, name[i]));
        }else if(argv[2] != NULL){
            if(strcmp(argv[2], "-d") == 0 ){ //who postet how much in symbols
                printf("\n %s posted %d symbols", name[i], countSymbols(file_pointer, name[i]));
            }else if(strcmp(argv[2], "-s") == 0 ){ //how many emojis
                printf("\n %s posted %d emojis", name[i], countEmojis(file_pointer, name[i]));
            }else if(strcmp(argv[2], "-h") == 0 ){ //what time most posted
                printf("\n %s posted around the hour %d the most", name[i], countTimePosted(file_pointer, name[i]));
            }else{ //no argument for - given so just count how many messages
                printf("\n %s posted %d messages", name[i], countMessages(file_pointer, name[i]));
            }
        }
    }

    printf("\n \n End of Code reached");
    fclose(file_pointer);
    return 0;
}



void Unicls(){
    #ifdef _WIN32
        system("cls"); //Win
    #else
        system("clear"); // Unix 
    #endif
}


int countMessages(FILE *file_pointer, char* person){ //no flag
    int count = 0;
    char line[1000];
    while(fgets(line, 1000, file_pointer) != NULL){
        if (strstr(line, person) != NULL && line[19] == ']' && strstr(line + 19, ":") != NULL) { //this if checks that if the name is in a message that that wont count those in it aswell
            int personIndex = strstr(line, person) - line;
            int colonIndex = strstr(line + 19, ":") - line;
            if (personIndex < colonIndex) {
                count++;  
            }
        }
    }
    return count;
}


int countSymbols(FILE *file_pointer, char* person){ //-d
    int count = 0;
    char line[1000];
    while(fgets(line, 1000, file_pointer) != NULL){
        if (strstr(line, person) != NULL && line[19] == ']' && strstr(line + 19, ":") != NULL) { //this if checks that if the name is in a message that that wont count those in it aswell
            int personIndex = strstr(line, person) - line;
            int colonIndex = strstr(line + 19, ":") - line;
            if (personIndex < colonIndex) {
                for(int i = 0; line[i] != '\0'; i++){
                    if(line[i] != ' ' && line[i] != '\n'){
                        count++;
                    }
                }    
            }
        }
    }
    return count;
}


int countEmojis(FILE *file_pointer, char* person) { //covers most emojis till now
    int count = 0;
    char line[1000];
    while (fgets(line, 1000, file_pointer) != NULL) {
        if (strstr(line, person) != NULL) {
            if (strstr(line, person) != NULL && line[19] == ']' && strstr(line + 19, ":") != NULL) { //this if checks that if the name is in a message that that wont count those in it aswell
                int personIndex = strstr(line, person) - line;
                int colonIndex = strstr(line + 19, ":") - line;
                if (personIndex < colonIndex) {
                    for (int i = 0; line[i] != '\0'; i++) {
                        if((line[i] == -16 && line[i+1] == -97 && line[i+2]<0 && line[i+3]<0) && (i>22+strlen(person)) || (line[i-2] != ':' && line[i] == -30 && line[i+1]<0 && line[i+2]<0 && (i>21+strlen(person)))){
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;    
}


int countTimePosted(FILE *file_pointer, char* person){ //-h for time
    int count = 0, max = 0;
    int arr[24] = {0};
    char line[1000];
    while(fgets(line, 1000, file_pointer) != NULL){
        if (strstr(line, person) != NULL && line[19] == ']' && strstr(line + 19, ":") != NULL) { //this if checks that if the name is in a message that that wont count those in it aswell
            int personIndex = strstr(line, person) - line;
            int colonIndex = strstr(line + 19, ":") - line;
            if (personIndex < colonIndex) {
                arr[(line[11]-48)*10+(line[12]-48)]++; //i-8 is position of time and -48 to convert from ascii to int
            }
        }
    }

    for (int i = 0; i < 24; i++){ //finds highest number in array
        if(arr[i]>max){
            max=arr[i];
            count=i;
        }
    }
    return count; //returns what hour
}

/*
cat 1: normal emoji                 4 negative num and each starting with -16 -97
cat 2: household and other items    3 negative num and each starting with -30
cat 3: flags                        8 negative starting with -16 -97   (flags are two emojis out of cat 1 combined so they count as two form cat 1)
cat 4: numbers as emojis are shown as their ascii symbol num followed by -30 and -125 -93 and is 4 num in total
cat 5: copyricht and registered sign have extra: 2 negativ num starting with -62 and either -87 or -82

NOTICE: This code doesnt include cat 4 and 5

symbol that creates an issue (sort of found and fixed the issue since its a sepcial sign whatsapp uses): ‎
https://apps.timwhitlock.info/emoji/tables/unicode (where i got the emoji info from)
*/
