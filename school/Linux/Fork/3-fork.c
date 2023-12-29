#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){


	int pid=fork();

	if(!pid){ //child 1. to execute
		execl("/bin/touch", "touch", "test3.c", NULL);
	} else { //parent
		pid=fork();
		if(!pid){ //second to execute
			execl("test3Bash.sh", "test3Bash.sh", NULL);
		} else{ //parent
		 	pid=fork();
		 	if(!pid){ //child
		 		execl("/bin/gcc", "gcc", "test3.c", NULL);
		 	} else { //parent
		 		sleep(1);
		 		execl("a.out", "a.out", NULL);
		 	}
		}
	
	} 
	int status = 0; 
	waitpid(-1, &status, 0); 
	return 0;
}
