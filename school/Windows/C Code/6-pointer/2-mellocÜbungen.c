#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int *p1 = malloc(4*sizeof(int));
	
	*p1 = 3;
	
	printf("\nThis stuff is: %p", p1);
	printf("\nThis stuff is: %d", *p1);
	//free(p1); //value is gone but pointer still points at the same address
	printf("\nThis stuff is: %p", p1);
	printf("\nThis stuff is: %d", *p1);
	
	p1 += sizeof(int);
	*p1 = 2;
	printf("\nThis stuff is: %p", p1);
	printf("\nThis stuff is: %d", *p1);
	p1 += sizeof(int);
	*p1 = 3;
	printf("\nThis stuff is: %p", p1);
	printf("\nThis stuff is: %d", *p1);
	p1 += sizeof(int); //sizeof(int) adds 4 to it and the programm knows that it is an int so a ++ is enough
	*p1 = 3;
	printf("\nThis stuff is: %p", p1);
	printf("\nThis stuff is: %d", *p1);
	
	free(p1-3*sizeof(int)); //cleans up the rest of the reserved storage from melloc
	return 0;
}


