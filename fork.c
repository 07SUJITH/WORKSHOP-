#include<stdio.h>
#include<unistd.h>

int main(){

	pid_t pid;
	pid = fork();
  
	if(pid< 0){
		fprintf(stderr,"Fork Failed.\n");
		return 1;
	}
	else if(pid == 0)
		printf("Hello from child process!\n");
	else
		printf("Hello from parent process\n");	
	return 0;
}
/*
OUTPUT

Hello from child process!
Hello from parent process

*/
