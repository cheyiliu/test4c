#include <stdio.h>
/*1、输入 gcc hello.c -o hello；2、输入./hello*/
int main(){
	printf("hello world~\n");
	printf("%d\n", iterate(10));
	printf("line=%d, file=%s, func=%s\n", __LINE__, __FILE__, __func__);
	return 1;
}

int iterate(int value){
	if(1 == value){
		return 1;	
	}
	return iterate(value - 1) + value;
}
