#include <stdio.h>
/*1、输入 gcc hello.c -o hello；2、输入./hello*/
int main(){
	printf("hello world~\n");
	printf("%d\n", iterate(10));
	return 1;
}

int iterate(int value){
	if(1 == value){
		return 1;	
	}
	return iterate(value - 1) + value;
}
