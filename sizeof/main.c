#include <stdio.h>

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

int main() {
	printf("\n---------szieof 基本类型------\n");
	printf("szieof(char)   = %lu\n", sizeof(char));
	printf("szieof(short)  = %lu\n", sizeof(short));
	printf("szieof(int)    = %lu\n", sizeof(int));
	printf("szieof(long)   = %lu\n", sizeof(long));
	printf("szieof(float)  = %lu\n", sizeof(float));
	printf("szieof(double) = %lu\n", sizeof(double));

	printf("\n---------szieof 基本类型指针------\n");
	printf("szieof(char*)   = %lu\n", sizeof(char*));
	printf("szieof(short*)  = %lu\n", sizeof(short*));
	printf("szieof(int*)    = %lu\n", sizeof(int*));
	printf("szieof(long*)   = %lu\n", sizeof(long*));
	printf("szieof(float*)  = %lu\n", sizeof(float*));
	printf("szieof(double*) = %lu\n", sizeof(double*));

	printf("\n---------szieof 结构体，涉及结构体对齐的知识点------\n");
	printf("sizeof(struct s1) = %lu\n", sizeof(struct struct_s1));
	printf("sizeof(struct s2) = %lu\n", sizeof(struct struct_s2));
	printf("sizeof(struct s3) = %lu\n", sizeof(struct struct_s3));

	printf("\n---------地址 of 结构体变量------\n");
	struct struct_s2 ss2;
	printf("address of ss2   = %p\n", &ss2);
	printf("address of ss2.a = %p\n", &ss2.a);
	printf("address of ss2.b = %p\n", &ss2.b);
	printf("address of ss2.c = %p\n", &ss2.c);
	printf("address of ss2.d = %p\n", &ss2.d);

	printf("\n---------szieof 稍微复杂点的例子------\n");
	double* (*a)[3][6]; // a is a pointer to array[3][6], the array is of type double*;
	printf("%lu\n", sizeof(a)); // a为指针
	printf("%lu\n", sizeof(*a)); // *a为一个有3*6个指针元素的数组
	printf("%lu\n", sizeof(**a)); // **a为数组一维的6个指针
	printf("%lu\n", sizeof(***a)); // ***a为一维的第一个指针
	printf("%lu\n", sizeof(****a)); // ****a为一个double变量

	return 0;
}
