#include <iostream>
#include <vector>
using namespace std;
/*
 *  from https://github.com/cheyiliu/All-in-One/wiki/C--11%E4%B8%AD%E7%9A%84%E5%8F%B3%E5%80%BC%E5%BC%95%E7%94%A8%26%26 */
class obj {
public:
	obj() {
		cout << ">> create obj " << endl;
	}
	obj(const obj& other) {
		cout << ">> copy create obj " << endl;
	}
};

template<class T>
class container {
public:
	T* value;

public:
	container() :
			value(NULL) {
	}

	~container() {
		delete value;
	}

	container(const container& other) {
		value = new T(*other.value);
	}

	container(container&& other)
	{
		value = other.value;
		other.value = NULL;
	}

	const container& operator =(const container& other) {
		delete value;
		value = new T(*other.value);
		return *this;
	}

	container& operator =(container&& other)
	{
		delete value;
		value = other.value;
		other.value = NULL;
		return *this;
	}
	/*
	 * gcc中却无法通过编译，原因很简单：gcc期望的赋值函数的参数是const型的，
	 * 而这里为了交换成员，而不能使用const型。
	 */
//	const container& operator =(container& other) {
//		T* tmp = value;
//		value = other.value;
//		other.value = tmp;
//		return *this;
//	}
			void push_back(const T& item) {
				delete value;
				value = new T(item);
			}
		};

container<obj> foo() {
	container<obj> c;
	c.push_back(obj());

	cout << "---- exit foo ----" << endl;
	return c;
}

int main() {
	container<obj> k;
	k = foo();

}
