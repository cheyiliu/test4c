/*
 http://blog.csdn.net/pathuang68/article/details/4101999
 http://blog.csdn.net/haoel/article/details/1948051
 */
/*
 * c++对象内存布局 系列， TODO
 */
#include <iostream>
using namespace std;

class Base1 {
public:
	int m_base1;
	inline virtual void vfBase1_1() {
		cout << "This is in Base1::vfBase1_1()" << endl;
	}
};

class Base2: public Base1 {
public:
	int m_base2;
	inline virtual void vfBase2_1() {
		cout << "This is in Base2::vfBase2_1()" << endl;
	}
};

class Base3: public Base2 {
public:
	int m_Base3;
	inline virtual void vfBase3_1() {
		cout << "This is in Base3::vfBase3_1()" << endl;
	}
};

class Derived: public Base3 {
public:
	int m_derived;
	inline virtual void fd() {
		cout << "This is in Derived::fd()" << endl;
	}

	inline virtual void vfBase1_1() {
		cout << "This is in Derived::vfBase1_1()" << endl;
	}
	inline virtual void vfBase2_1() {
		cout << "This is in Derived::vfBase2_1()" << endl;
	}
	inline virtual void vfBase3_1() {
		cout << "This is in Derived::vfBase3_1()" << endl;
	}
};

typedef void (*VFun)(void);

template<typename T>

VFun virtualFunctionPointer(T* b, int i) {
	return (VFun) (*((long*) (*(long*) b) + i));
}

int main(void) {
	Derived d;
	cout << "The size of Derived object = /t" << sizeof(Derived) << endl;
	cout << endl;
	cout << "1st virtual function table: " << endl;
	int i = 0;
	while (virtualFunctionPointer(&d, i)) {
		VFun pVF = virtualFunctionPointer(&d, i++);
		pVF();
	}

	return 0;
}
