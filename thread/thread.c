#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* fun1(void* args){
	while(1){
		sleep(1);
		printf("func 1\n");
	}
}

void* fun2(void* args){
	while(1){
		sleep(2);
		printf("func 2\n");
	}
}

int main(){
	pthread_t pid1, pid2;
	if(pthread_create(&pid1, NULL, fun1, NULL)){
		return -1;
	}
	if(pthread_create(&pid2, NULL, fun2, NULL)){
		return -1;
	}

	int counter = 10;	
	while(counter > 0){
		counter--;
		sleep(1);	
	}

	printf("main exit ...\n");
	return 0;
}
/*
和我们以前编写的程序有所不同，多线程代码需要这样编译，输入gcc thread.c -o thread -lpthread
*/
