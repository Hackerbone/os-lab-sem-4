#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void){

	pid_t pid1;
	

	printf("Checking if someone runs this code or not\n");

	pid1 = fork();

	printf("\n==============================================\n");	

	if (pid1 == 0){
		printf("I am child: [Ran getpid()] %d\n", getpid());
		printf("[Returned fork() value]: %d\n", pid1);	
		printf("My PPID is %d\n==============================================\n", getppid());
	}

	else if(pid1 > 0){
		printf("I am parent proccess: [Ran getpid()] %d\n", getpid());
		printf("[Returned fork() value]: %d\n", pid1);	
		printf("My PPID is %d\n==============================================\n", getppid());
	}

	else if(pid1 == -1){
		printf("ERROR:\n");
	}


}


/*
Checking if someone runs this code or not

==============================================
I am parent proccess: [Ran getpid()] 9412
[Returned fork() value]: 9413
My PPID is 6269
==============================================

==============================================
I am child: [Ran getpid()] 9413
[Returned fork() value]: 0
My PPID is 9412
==============================================
*/