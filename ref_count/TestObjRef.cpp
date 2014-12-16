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

int main() {
	TestObj * ptr = new TestObj(); ptr->print();//初始化时引用计数为1
	ptr->retain();	ptr->print();
	ptr->retain();	ptr->print();
	ptr->retain();	ptr->print();

	ptr->release();
	ptr->release();
	ptr->release();
	ptr->release();
}
#endif // __TEST_OBJ_H__
