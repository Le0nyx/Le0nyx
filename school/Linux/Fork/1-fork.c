#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	int pidC = 0, pidP = 0;
	
	int pid = fork(); //this gives the parent the pid of the kid
	if(pid==0){  //Child
		pidC = getpid();
		printf("\n The pid of the Child is %d.", pidC);
		sleep(2);
		} else { //Parent
			pidP = getpid();
			printf("\n The pid of the Parent is %d", pidP);
			waitpid(pid, NULL, 0); //waits here until kid is dead
			printf("\n Good Morning %d", pid);
			}
	
	
//the parent process still needs to print the pid of the child and say goodmorning
	return 0;
}
