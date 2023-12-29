#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sig_handler(int signum){
	printf("\n Insider handler function\n");
}




int main(){
	//signal(SIGINT, sig_handler); handler does it
	signal(SIGINT, SIG_IGN); //no handler
	for(int i  = 1;;i++){
		printf("%d : Inside main function\n", i);
		sleep(1);
	}

	return 0;
}
