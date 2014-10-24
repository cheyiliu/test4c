/*
 ============================================================================
 Name        : test4c.c
 Author      : abc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	pid_t fpid; //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
	if (fpid < 0)
		printf("error in fork!");
	else if (fpid == 0) {
		printf("child process, pid is %d \n", getpid());
		count++;
	} else {
		printf("parent process, pid is %d \n", getpid());
		count++;
	}
	printf("统计结果是: %d \n", count);
	return EXIT_SUCCESS;
}
