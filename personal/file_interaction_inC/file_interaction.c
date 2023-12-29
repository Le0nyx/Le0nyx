#include<stdio.h>

int main(){
    FILE *file_pointer; //initializing
    int a = 0;
    char *num[100]; //needs to have size in declaration
    file_pointer = fopen("text.txt", "w+"); //opening file

    if(file_pointer == NULL){ //error handeling
        printf("\n ERROR OCCURED \n");
        return 0;
    }

    fprintf(file_pointer, "hey "); //writes yo? into the first line and first 3 symbols
    fseek(file_pointer, 0, SEEK_SET); //moves "curser" to start again

    fseek(file_pointer, 4, SEEK_SET);
    fprintf(file_pointer, "%d", 15); //integer gets written into it but is still seen as a character inside the txt. can be read back tho to int
    fseek(file_pointer, 0, SEEK_SET);

    fscanf(file_pointer, "%3s", &num); //get something out of file
    fseek(file_pointer, 4, SEEK_SET);
    fscanf(file_pointer, "%d", &a);
    fseek(file_pointer, 0, SEEK_SET);

    printf("\n %s  %d", num, a);
    fclose(file_pointer); //closing file
    return 0;
}
