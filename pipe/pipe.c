#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int pipe_default[2];

int main(){
	pid_t pid;
	char buffer[32];
	memset(buffer, 0, 32);

	if(pipe(pipe_default) < 0){
		printf("failed to create pipe\n");
		return 0;
	}

	if(0 == (pid = fork())){
		close(pipe_default[1]);
		sleep(1);
		if(read(pipe_default[0], buffer, 32) > 0){
			printf("receive data from sever, %s\n", buffer);
		}
		close(pipe_default[0]);
	}else{
		close(pipe_default[0]);
		if(-1 != write(pipe_default[1], "hello 123", strlen("hello 123"))){
			printf("send data to client, hello 123\n");
		}
		close(pipe_default[1]);
		waitpid(pid, NULL, 0);
	}

	return 1;
}


/*
原型：
int pipe(int pipefd[2]);

       pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication.  The array pipefd is used to return two file descriptors refer‐
       ring to the ends of the pipe.  pipefd[0] refers to the read end of the pipe.  pipefd[1] refers to the write end of the pipe.  Data written to the write  end  of  the
       pipe is buffered by the kernel until it is read from the read end of the pipe.  
*/
