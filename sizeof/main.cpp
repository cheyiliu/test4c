/**
 * see https://github.com/cheyiliu/All-in-One/wiki/sizeof
 * 1. 数据自身的对齐
 * 2. 整个结构体的对齐
 */

#include <stdio.h>

class class_c1 {
	char a;
	double b;
	int c;
	char d;
};

class class_c2 { // 多了虚函数后， 将多一个指针指向虚汗数表
	char a;
	double b;
	int c;
	char d;
	virtual void printf() {
	}
	virtual void printf2() {
	}
	virtual ~class_c2() {
	}
};

struct struct_s1 {
	char a;
	double b;
	int c;
	char d;
};

struct struct_s2 {
	char a;
	char b;
	int c;
	double d;
};

#pragma pack (2) // 设置结构体的边界对齐为x个字节，若x=1 则结构体成员在内存中是连续的
struct struct_s3 { // 成员和struct_s2一样，顺序和类型，注意对比
	char a;
	char b;
	int c;
	double d;
};
#pragma pack ()

struct s1 {
	int i :8; // 位域
	int j :4;
	int a :3;
	double b;

};

struct s2 {
	int i;
	int j;
	double b;
	int a;
};

struct s3 {
	int i;
	int j;
	int a;
	double b;
};

struct s4 {
	int i :31;
	int j :31;
	int a :2; // 改为1再试试
	double b;
};

typedef struct { // from http://akaedu.github.io/book/ch19s04.html
	unsigned int one :1; // 1B，可继续分配3b (1+3)
	unsigned int two :3;
	unsigned int three :10; // 2B，可继续分配5b (10+5)
	unsigned int four :5;
	unsigned int :2; // 1B，上一步分配的2B只剩下1b，不够
	unsigned int five :8; // 1B
	unsigned int six :8; // 1B。
} demo_type; // 1.数据自身对齐 1B+2B+1B+1B+1B=6B。 2.结构体以4B来对齐，故最终结果是8B

void printSizeof(int arg[]) {
	printf("sizeof(arg)   = %lu\n", sizeof(arg)); // 数组类型自动弱化为指针类型
}

int main() {
	printf("\n---------sizeof 类------\n");
	printf("sizeof(class_c1) = %lu\n", sizeof(class_c1));
	printf("sizeof(class_c2) = %lu\n", sizeof(class_c2));

	printf("\n---------sizeof 基本类型------\n");
	printf("sizeof(char)   = %lu\n", sizeof(char));
	printf("sizeof(short)  = %lu\n", sizeof(short));
	printf("sizeof(int)    = %lu\n", sizeof(int));
	printf("sizeof(long)   = %lu\n", sizeof(long));
	printf("sizeof(float)  = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));

	printf("\n---------sizeof 基本类型指针------\n");
	printf("sizeof(char*)   = %lu\n", sizeof(char*));
	printf("sizeof(short*)  = %lu\n", sizeof(short*));
	printf("sizeof(int*)    = %lu\n", sizeof(int*));
	printf("sizeof(long*)   = %lu\n", sizeof(long*));
	printf("sizeof(float*)  = %lu\n", sizeof(float*));
	printf("sizeof(double*) = %lu\n", sizeof(double*));

	printf("\n---------sizeof 结构体，涉及结构体对齐的知识点------\n");
	printf("sizeof(struct struct_s1) = %lu\n", sizeof(struct struct_s1));
	printf("sizeof(struct struct_s2) = %lu\n", sizeof(struct struct_s2));
	printf("sizeof(struct struct_s3) = %lu\n", sizeof(struct struct_s3));

	printf("sizeof(struct s1) = %lu\n", sizeof(struct s1));
	printf("sizeof(struct s2) = %lu\n", sizeof(struct s2));
	printf("sizeof(struct s3) = %lu\n", sizeof(struct s3));
	printf("sizeof(struct s4) = %lu\n", sizeof(struct s4));

	printf("sizeof(demo_type) = %lu\n", sizeof(demo_type));

	printf("\n---------地址 of 结构体变量------\n");
	struct struct_s2 ss2;
	printf("address of ss2   = %p\n", &ss2);
	printf("address of ss2.a = %p\n", &ss2.a);
	printf("address of ss2.b = %p\n", &ss2.b);
	printf("address of ss2.c = %p\n", &ss2.c);
	printf("address of ss2.d = %p\n", &ss2.d);

//	struct s4 varS4;
//	printf("address of varS4   = %p\n", &varS4);
//	printf("address of varS4.i = %p\n", &varS4.i);//main.cpp:120: error: attempt to take address of bit-field structure member ‘s4::i’
//	printf("address of varS4.j = %p\n", &varS4.j);
//	printf("address of varS4.a = %p\n", &varS4.a);
//	printf("address of varS4.b = %p\n", &varS4.b);

	printf("\n---------sizeof 稍微复杂点的例子------\n");
	double* (*a)[3][6]; // a is a pointer to array[3][6], the array is of type double*;
	printf("%lu\n", sizeof(a)); // a为指针
	printf("%lu\n", sizeof(*a)); // *a为一个有3*6个指针元素的数组
	printf("%lu\n", sizeof(**a)); // **a为数组一维的6个指针
	printf("%lu\n", sizeof(***a)); // ***a为一维的第一个指针
	printf("%lu\n", sizeof(****a)); // ****a为一个double变量

	printf("\n---------sizeof 函数参数------\n");
	int array[10] = { 0, };
	printSizeof(array);

	return 0;
}
