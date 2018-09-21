#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int a;

int main(){
	int c;
	a = 1;
	c = 2;

	if(fork() == 0){
		a = 10;
		c = 20;

		if(fork() == 0){
			c = 30;
			printf("a = %d, c = %d\n", a, c);
			exit(0);
		}else{
			wait(NULL);
			printf("a = %d, c = %d\n", a, c);
			exit(0);
		}
	}
	printf("a = %d, c = %d\n", a, c);
}