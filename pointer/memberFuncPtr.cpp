#include <iostream>
#include <stdio.h>
using namespace std;

class A {
public:
	int func1(int x, int y) {
		printf("A::func:x=%d,y=%d\n", x, y);
		return (x < y ? x : y);
	}
	virtual int func2(int x, int y) {
		printf("A::func:x=%d,y=%d\n", x, y);
		return (x > y ? x : y);
	}
};
class B: public A {
public:
	virtual int func2(int x, int y) {
		printf("B::func:x=%d,y=%d\n", x, y);
		return (x + y);
	}

};
typedef int (A::*p)(int, int); //指针名前一定要加上所属类型类名 A::的限定

template<class T>
class C {
public:
	T c;
	void Print() {
		int (T::*p)(int, int)=&T::func2;
		cout << (c.*p)(4, 5) << endl;
	}
};
int main() {
	A a; //因为成员函数地址的解引用必须要附驻与某个对象的地址，所以我们必须创建某个对象。
	B b;
	p fun = &A::func1;

	cout << (a.*fun)(4, 5) << endl;
	cout << (b.*fun)(4, 5) << endl << endl;

	fun = &A::func2;
	cout << (a.*fun)(4, 5) << endl; //请注意这里调用的是虚函数，嘿嘿 还真神奇 类成员函数指针也支持多态。
	cout << (b.*fun)(4, 5) << endl << endl;

	C<A> ca;
	C<B> cb;

	ca.Print();
	cb.Print();
	return 0;
}
