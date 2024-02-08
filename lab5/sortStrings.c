#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h> 
#include <sys/wait.h>

static int myCompare(const void* a, const void* b) 
{ 
    return strcmp(*(const char**)a, *(const char**)b); 
} 

void sort(char* arr[], int n) 
{ 
    qsort(arr, n, sizeof(const char*), myCompare); 
} 


int main(int argc, char *argv[]){
	int status;

    int n = argc; 
    int i; 


	pid_t pid1;
	
	pid1 = fork();


	if (pid1 == 0){
	printf("\n==============================================\n");	
		printf("I am child so I am going to sort strings\n");		
	    sort(argv, n);
        for (i = 0; i < n; i++) 
	        printf("%d: %s \n", i, argv[i]);  
	printf("==============================================\n");	
	}

	else if(pid1 > 0){
		wait(&status);
		if(WIFEXITED(status)){
		printf("\n==============================================\n");	
			printf("I am parent proccess\n");
	        for (i = 0; i < n; i++) 
		        printf("%d: %s \n", i, argv[i]);  
		printf("==============================================\n");	
		}}

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