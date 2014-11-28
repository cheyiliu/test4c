/**
 * see https://github.com/cheyiliu/All-in-One/wiki/sizeof
 * 1. 数据自身的对齐
 * 2. 整个结构体的对齐
 * 本例重点关注有继承关系的class的sizeof (继承关系自己画画图就好)
 * 结论：
 * v-table指针的个数=有v-table指针的父类个数。
 * 空类的sizeof = 1, 静态成员变量的size不算在类的sizeof上。

 * http://www.cnblogs.com/chaoguo1234/archive/2013/05/12/3074534.html
 */

#include <stdio.h>

class base1 {
public:
	// 静态的数据成员属于类，而不属于类的对象，因此，类对象的大小不包括静态数据成员。
	static int static_member;
public:
	virtual void printf() {
	}
	virtual ~base1() {
	}
};

class base2 {
public:
	virtual void printf() {
	}
	virtual ~base2() {
	}
};

class base3 {
public:
	virtual void printf() {
	}
	virtual ~base3() {
	}
};
// 空类中没有任何数据成员。按照公式计算，此类的对象所占用的内存空间应该为0.
// 而实际情况是，空类的对象对象长度为1字节。如果类对象完全不占用内存空间，
// 就无法取得实例化对象的地址，this指针失效。而类的定义有成员数据和成员函数组成，
// 在没有成员数据的情况下，仍可以有成员函数，因此，就为空类分配了1字节的空间用来实例化类。
// 这1字节并没有被使用。占位而已。
class class_c0 {
};

class class_c1 { // 1个v-table指针
	virtual void printf() {
	}
	virtual void printf1() {
	}
	virtual ~class_c1() {
	}
};

class class_c2: public base1 { // 1个v-table指针，自身的放入到了第一个基类
	virtual void printf() {
	}
	virtual void printf2() {
	}
	virtual ~class_c2() {
	}
};

class class_c3: public base1, base2 { // 2个v-table指针，自身的放入到了第一个基类
	virtual void printf() {
	}
	virtual void printf3() {
	}
	virtual ~class_c3() {
	}
};

class class_c4: public base1, base2, base3 { // 3个v-table指针，自身的放入到了第一个基类
	virtual void printf() {
	}
	virtual void printf4() {
	}
	virtual ~class_c4() {
	}
};

class class_c5: public base1, base2, base3 { // 3个v-table指针

};

class class_c6: public class_c5 { // 3个v-table指针

};
int main() {
	printf("\n---------sizeof 类------\n");
	printf("sizeof(base1) = %lu\n", sizeof(base1));
	printf("sizeof(base2) = %lu\n", sizeof(base2));
	printf("sizeof(base3) = %lu\n", sizeof(base3));

	printf("sizeof(class_c0) = %lu\n", sizeof(class_c0));
	printf("sizeof(class_c1) = %lu\n", sizeof(class_c1));
	printf("sizeof(class_c2) = %lu\n", sizeof(class_c2));
	printf("sizeof(class_c3) = %lu\n", sizeof(class_c3));
	printf("sizeof(class_c4) = %lu\n", sizeof(class_c4));
	printf("sizeof(class_c5) = %lu\n", sizeof(class_c5));
	printf("sizeof(class_c6) = %lu\n", sizeof(class_c6));

	return 0;
}
