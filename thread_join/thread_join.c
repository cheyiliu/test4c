#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* func(void* args){
	sleep(2);
	printf("this is thread func\n");
}

int main(){
	pthread_t pid;
	if(pthread_create(&pid, NULL, func, NULL)){
		return -1;
	}

	pthread_join(pid, NULL);
	printf("this is end of main\n");

	return 0;
}
