// erstelle mit fork Kind und Vater.  Der Elternprozess schickt einen String an den Kindprozess.
//der Kindprozess printed diesen. Sobald das Kind beended soll der Vater Fertig printen

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	
	int fd[2]; //creates an array
	//pipe(fd); //creates a pipe out of that array. One to recieve 0 and one to write 1
	
	
// EXPLANATION FOR CLOSE: THe pipe works for either process. For child and parent individual
// if the parent writes it shall close before to recieve and after it send also the write
// same with the other way around. You can also close the child early if intended to so it wont run further
	
	
	if(pipe(fd)==-1){ //if pipe gets an error it should close the programm
		printf("\n Error occured");
		return 0;
	}
	
	
	int pid1 = fork(); //
	
	if(pid1){ //Eltern Prozess
		close(fd[0]); //turn off to recieve 
		char string1[] = "Hallo there";
		
		write(fd[1], string1, sizeof(string1)); //schickt den String in die Pipe
		close(fd[1]); //close it all
		
		
		wait(NULL); //could also use waitpid()
		printf("\n Fertig \n");
	
	} else{ //Kind Prozess
		close(fd[1]); 
		char printig[100]; //needs to be larger than the message you intend to send
		
		read(fd[0], printig, sizeof(printig));
		close(fd[0]);
		printf("\n The Child Recieved: %s", printig);
		
		//child shall close ig	
	}
	
	return 0;
}

