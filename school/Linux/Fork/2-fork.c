#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int pid=fork();
	
	if(pid){ //parent [work always goes through all parents first and then through the children]
		pid = fork(); //WARNING: the ip is getting changed by the fork so be careful to overwrite the old pid
		if(pid){ //parent
		printf("It reaches this ");
			execl("/bin/mkdir", "mkdir", "test", NULL);
		} else{
			sleep(1);
			execl("/bin/rm", "rm", "-r", "test", NULL);
		}
	}else{
		execl("/bin/ls", "ls", "-1", NULL);
	}
	
	printf("Final I made it");
	return 0;
}
