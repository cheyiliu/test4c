#include <iostream>
#include <boost/shared_ptr.hpp>
using namespace std;
using namespace boost;
class Test {
public:
	Test(string s) {
		str = s;
		cout << " Test:" << str << endl;
	}
	~Test() {
		cout << "~Test:" << str << endl;
	}
	string& getStr() {
		return str;
	}
	void setStr(string s) {
		str = s;
	}
	void print() {
		cout << str << endl;
	}
private:
	string str;
};

/*
 * http://www.cnblogs.com/hujian/archive/2012/12/10/2810754.html
 * https://github.com/cheyiliu/All-in-One/wiki/smart_ptr
 * */
int main() {
	{
		shared_ptr<Test> ptest123(new Test("ptest123"));
		shared_ptr<Test> ptest456(new Test("ptest456"));

		cout << ptest123.use_count() << endl;
		cout << ptest456.use_count() << endl;

		ptest456 = ptest123;

		cout << ptest123.use_count() << endl;
		cout << ptest456.use_count() << endl;
		cout << "----------" << endl;
		ptest456->print();
		(*ptest456).print();
//		(*ptest456)->print();
		cout << "----------" << endl;
	}
	{
		Test *pTest = new Test(
				"Test share the same obj by more than one shared_ptr");
		shared_ptr<Test> temp1(pTest);
		assert(temp1.use_count() == 1);
//		shared_ptr<Test> temp2(pTest);
//		assert(temp2.use_count() == 1);
	} // temp1和temp2都离开作用域，它们都销毁pInt，会导致两次释放同一块内存
	cout << "end of main !\n";
	return 0;
}
