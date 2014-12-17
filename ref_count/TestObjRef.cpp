#ifndef __TEST_OBJ_H__
#define __TEST_OBJ_H__
#include "Ref.h"
#include <stdio.h>
class TestObj: public Ref {

public:
	TestObj() {
		printf("TestObj\n");
	}
	virtual ~TestObj() {
		printf("~TestObj\n");
	}

	inline void print() {
		printf("print, ref count = %d\n", getReferenceCount());
	}
};

class UseTestObj {

public:
	TestObj* mObj;
	void setTestObj(TestObj* obj) {
		mObj = obj;
		mObj->retain();
	}
	~UseTestObj() {
		printf("~UseTestObj\n");
		mObj->release();
	}
};
/*
 * release retain配对 依然麻烦， 我们需要只能指针， 见../smart_ptr
 */
int main() {
	TestObj * ptr = new TestObj();
	ptr->print(); //初始化时引用计数为1
	ptr->retain();
	ptr->print();
	ptr->retain();
	ptr->print();
	ptr->retain();
	ptr->print();

	ptr->release();
	ptr->release();
	ptr->release();

	{
		TestObj testobj;
	}

	{
		UseTestObj useTestObj;
		useTestObj.setTestObj(ptr);
	}

	ptr->release();
	printf("end of main\n");
}
#endif // __TEST_OBJ_H__
