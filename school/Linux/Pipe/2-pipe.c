//AA3: Elternprozess liest einen String ein der es dann an Kind schickt und sortiert und das Kind schickt dann weiter an nächstes Kind gibt zu konvertieren und umdrehen. Elternprozess printed dann beide

//scuffed programm, but ig it works / ignore the warnings

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>


int main(){
	
	int fd[2];
	pipe(fd);
	int fd1[2]; //first kid
	pipe(fd1);
	int fd2[2]; //second kid
	pipe(fd2);
	
	if(pipe(fd)==-1){ //if pipe gets an error it should close the programm
		printf("\n Error occured");
		return 0;
	}

	int pid1 = fork();
	
	if(pid1){ //parent process
		close(fd[0]); //turn off to recieve
		close(fd1[1]);//turn off to write
		close(fd2[1]);
		char input[] = "3,1,0,10,8,324,13"; //can actually change the combination
		write(fd[1], input, sizeof(input));
		close(fd[1]);
		
		char sorted[30];
		read(fd1[0], sorted, sizeof(sorted));
		
		char inverted[30];
		read(fd2[0], inverted, sizeof(inverted));
		
		
		wait(NULL); //end of programm
		
		printf("\n 1. Sorted: %s", sorted);
		printf("\n 2. Inverted: %s", inverted);
		
		printf("\n Ende \n");
		
	} else{ //child process
		close(fd[1]); //close to write
		close(fd1[0]);
		char given[30];
		read(fd[0], given, sizeof(given));
		close(fd[0]); //closed
		
		//printf("\n Recieved: %s", given);
		
		int array[30]; // assume that we're converting up to 30 numbers
		int counter = 0;
		int num_digits = 0;
		for (int i = 0; i < 30 && given[i] != '\0'; i++) { // check for null termination of string
  			if (given[i] == ',') {
   				 array[counter] = num_digits;
   				 num_digits = 0;
   				 counter++;
  			} else {
   				 num_digits = num_digits * 10 + (given[i] - '0');
  			}
		}
		
		if (num_digits > 0) { // handle the last number in the string
			  array[counter] = num_digits;
			  counter++;
		}
		
		
		int temp1 = 0; //bubble sort the array
		int array_size = 6;
	
		for(int i = 0;i<array_size;i++){
    			for(int j = 0;j<array_size;j++){
       				 if(array[j]>=array[j+1]){ //swapping
         				   temp1 = array[j];
         				   array[j]=array[j+1];
         				   array[j+1]=temp1;
        			}
   			 }
		}
		
		char sorted[50] = "";
		for(int i = 0;i<7;i++){
			sprintf(sorted, "%s%d, ", sorted, array[i]);
		} 
		
		//printf("\n Reached: %s", sorted);
		write(fd1[1], sorted, sizeof(sorted));
		close(fd[1]);
		
	//the inverting in a new child is still missing
		int pid2 = fork();
		
		if(pid2==0){ //second kid
			char inverted[50] = "";
			for(int i = 6;i>=0;i--){
				sprintf(inverted, "%s%d, ", inverted, array[i]);
			} 	
			//printf("\n Ended with: %s", inverted);
			write(fd2[1], inverted, sizeof(inverted));
			close(fd2[1]);
			return 0;
		}
		
		
		
		return 0;
	}//end of child
	
	
	return 0;
}
