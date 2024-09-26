#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#include<time.h>



int main(int argc, char* argv[]){
    //initialize the arduino

	system("cls");
	printf("\n ----------------------------------\n \n \n");
	//here the code for the arduino
	unsigned long now = time(NULL);
    printf("Current time as a Unix timestamp: %ldL\n", now);
	chdir("####");


	// Open the .ino file for reading
    FILE *input_file = fopen("####", "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open a new file for writing
    FILE *output_file = fopen("####", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }
	// Copy the contents of the input file to the output file
	char buffer1[2024];
	while(fgets(buffer1, sizeof(buffer1), input_file) != NULL) {
		if(strstr(buffer1, "unsigned long currentTime") != NULL){
			fprintf(output_file, "unsigned long currentTime = %ld;\n", now);
		}else{
			fputs(buffer1, output_file);
		}
	}
    // Close both files
    fclose(input_file);
    fclose(output_file);

	//compile and upload
	system("arduino-cli compile -b arduino:avr:mega ");
	system("arduino-cli upload -b arduino:avr:mega -p COM3 \"####"); //uploads the stuff
    return 0;
}
