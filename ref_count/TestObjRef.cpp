#ifndef __TEST_OBJ_H__
#define __TEST_OBJ_H__
#include "Ref.h"
#include <stdio.h>
#include <boost/shared_ptr.hpp>
using namespace boost;

class TestObj: public Ref {
public:
	TestObj() {
		printf(" TestObj %p\n", this);
	}
	virtual ~TestObj() {
		printf("~TestObj %p\n", this);
	}

	inline void print() {
		printf("print, ref count = %d\n", getReferenceCount());
	}
};

/*
 * release retain配对 依然麻烦， 我们需要只能指针， 见../smart_ptr
 */
class UseTestObj {
public:
	TestObj* mObj;

	UseTestObj(TestObj* obj) {
		mObj = obj;
		mObj->retain();
		printf(" UseTestObj %p\n", this);
	}
	~UseTestObj() {
		printf("~UseTestObj %p\n", this);
		mObj->release();
	}
};

class UseTestObj_use_smart_ptr { //用智能指针来改造
public:
	shared_ptr<TestObj> mObj;
	UseTestObj_use_smart_ptr(shared_ptr<TestObj> obj) {
		mObj = obj;
//		mObj->retain();
		printf(" UseTestObj_use_smart_ptr %p\n", this);
	}
	~UseTestObj_use_smart_ptr() {
		printf("~UseTestObj_use_smart_ptr %p\n", this);
//		mObj->release();
	}
};

/*
 * release retain配对 依然麻烦， 我们需要只能指针， 见../smart_ptr
 */
int main() {
	printf("-----begin of main\n");
	TestObj * ptr = new TestObj();	ptr->print(); //初始化时引用计数为1
	ptr->retain();	ptr->print(); //2
	ptr->retain();	ptr->print(); //3
	ptr->retain();	ptr->print(); //4

	ptr->release();	ptr->print(); //3
	ptr->release();	ptr->print(); //2
	ptr->release();	ptr->print(); //1

	{ // 引用计数
		UseTestObj useTestObj(ptr);
	}
	ptr->print(); //1，只要上面块作用域中retain/release配对了，则计数器仍然为进代码块之前的的值，
	//	ptr->release();//若再release，则ptr被删除。

	{ // 智能指针，解除retain release配对的麻烦
		printf("-----begin of block, line = %d\n", __LINE__);
		shared_ptr<TestObj> obj(ptr);
		UseTestObj_use_smart_ptr useTestObj(obj);
		printf("-----end   of block, line = %d\n", __LINE__);
	}

	printf("-----end of main\n");
}
#endif // __TEST_OBJ_H__
