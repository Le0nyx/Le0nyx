#include<stdio.h>
#include<stdlib.h>

int primenum(int);

int main(){
    for(int i = 0;i<100+1;i++){ //primenumbers till 100
        int a;
        a = primenum(i);
        if(a==1){
            printf("\n%d Number is a Primenumber", i);
        }else{
            printf("\n%d Number is not a Primenumber", i);
        }
    }
    return 0;
}


int primenum(int eingabe){
	int isPrime=1;
	int i=2;
	while (isPrime == 1 && (eingabe/2+1) > i ) { //most efficient is to only look to the root of eingabe  +1 cuz of the 4
		if(eingabe%i == 0) {
			isPrime= 0;
            return 0;	
		}
		i++;
	}
	if (isPrime == 1) {
        return 1;
	}
}