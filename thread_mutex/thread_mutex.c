#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

static int value = 0;
pthread_mutex_t mutex;

void* func(void* args){
	while(1){
		pthread_mutex_lock(&mutex);
//		sleep(1);
		value ++;
		printf("value = %d\n", value);
		pthread_mutex_unlock(&mutex);
	}
}

int main(){
	pthread_t pid1, pid2;
	pthread_mutex_init(&mutex, NULL);

	if(pthread_create(&pid1, NULL, func, NULL)){
		return -1;
	}

	if(pthread_create(&pid2, NULL, func, NULL)){
		return -1;
	}

	int count = 10;
	while(count > 0){
		count --;
		sleep(1);	
	}
	printf("main exit ...");	
	
	return 0;
}
