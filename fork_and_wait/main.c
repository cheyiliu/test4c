#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if(0 == pid){
		printf("this is child process, pid=%d\n", getpid());
		sleep(5);// sleep 5 seconds
	}else{
		wait(NULL);
		printf("this is parent process, pid=%d\n", getpid());
	}
	return 1;
}

/*
man wait,
All  of  these  system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed.  A
       state change is considered to be: the child terminated; the child was stopped by a signal; or the child was resumed by a signal. 

 The wait() system call suspends execution of the calling process until one of its children terminates.

*/
