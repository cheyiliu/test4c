#include <unistd.h>
#include <stdio.h>
/*
 * from http://blog.csdn.net/jason314/article/details/5640969
 * 在语句fpid=fork()之前，只有一个进程在执行这段代码，但在这条语句之后，就变成两个进程在执行了，
 * 这两个进程的几乎完全相同，将要执行的下一条语句都是if(fpid<0)……
 为什么两个进程的fpid不同呢，这与fork函数的特性有关。fork调用的一个奇妙之处就是它仅仅被调用一次，
 却能够返回两次，它可能有三种不同的返回值：
 1）在父进程中，fork返回新创建子进程的进程ID；
 2）在子进程中，fork返回0；
 3）如果出现错误，fork返回一个负值；

 在fork函数执行完毕后，如果创建新进程成功，则出现两个进程，一个是子进程，一个是父进程。在子进程中，
 fork函数返回0，在父进程中，fork返回新创建子进程的进程ID。我们可以通过fork返回的值来判断当前进程
 是子进程还是父进程。*/

int testFork() {
	printf("test fork \n");
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
	return 0;
}
