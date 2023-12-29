//child waits for signal - parents send signal to kid - parent waits for response - child recieved from parent - recieved response signal from kid 

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

void sig_child(){
	printf("C: Recieved a signal from P \n");
	kill(getppid(), SIGUSR2);
}


void sig_parent(){
	printf("P: Recieved a response signal from child \n");
	
}



int main(){
	
	int main_pid = getpid();
	int pid = fork();
	
	if(pid<0){ //if error occurs
		printf("Fork failed");
		exit(1);
	}
	
	
	if(pid){ //parent
		signal(SIGUSR2, sig_parent);
		sleep(1);
		printf("P: Sending Signal to C \n");
		kill(pid, SIGUSR1); //sends to kid
		printf("P: Waiting for response \n");
		pause();
	
	
	
	}else{ //kid
		signal(SIGUSR1, sig_child);
		printf("C: Waiting for signal \n");
		pause();
	
	
	
	
	}
	
	return 0;
}
