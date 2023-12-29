#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NSIZE 16


char *n1 = "Nachricht 1";
char *n2 = "Nachricht 2";

int main ()
{

	char buffer[NSIZE];

	int fd[2], i;

	if(pipe(fd)<0){
		exit(1);
	}

	// S c h r e i b e n
	write(fd[1],n1 , NSIZE);
	write(fd[1],n2 , NSIZE);

	// Lesen
	for(i=0;i<2;i++){
		read(fd[0] ,buffer ,NSIZE);
		printf("%s\n", buffer);
	}
	
	return 0;

}
