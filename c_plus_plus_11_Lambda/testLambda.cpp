#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
// from http://www.cnblogs.com/hujian/archive/2012/02/14/2350306.html
class CTest {
public:
	CTest() :
			m_nData(20) {
		cout << " CTest()" << endl;
	}
	~CTest() {
		cout << "~CTest()" << endl;
	}
	void TestLambda() {
		cout << "TestLambda begin ..." << endl;
		vector<int> vctTemp;
		vctTemp.push_back(1);
		vctTemp.push_back(2);

		// 无函数对象参数，输出：1 2
		{
			cout << "无函数对象参数，输出：1 2" << endl;
			for_each(vctTemp.begin(), vctTemp.end(),
					[](int v) {cout << v << endl;});
		}

		// 以值方式传递作用域内所有可见的局部变量（包括this），输出：11 12
		{
			cout << "以值方式传递作用域内所有可见的局部变量（包括this），输出：11 12" << endl;
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(),
					[=](int v) {cout << v+a << endl;});
		}

		// 以引用方式传递作用域内所有可见的局部变量（包括this），输出：11 13 12
		{
			cout << "以引用方式传递作用域内所有可见的局部变量（包括this），输出：11 13 12" << endl;
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(),
					[&](int v)mutable {cout << v+a << endl; a++;});
			cout << a << endl;
		}

		// 以值方式传递局部变量a，输出：11 13 10
		{
			cout << "以值方式传递局部变量a，输出：11 13 10" << endl;
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(),
					[a](int v)mutable {cout << v+a << endl; a++;});
			cout << a << endl;
		}

		// 以引用方式传递局部变量a，输出：11 13 12
		{
			cout << "以引用方式传递局部变量a，输出：11 13 12" << endl;
			int a = 10;
			for_each(vctTemp.begin(), vctTemp.end(),
					[&a](int v) {cout << v+a << endl; a++;});
			cout << a << endl;
		}

		// 传递this，输出：21 22
		{
			cout << "传递this，输出：21 22" << endl;
			for_each(vctTemp.begin(), vctTemp.end(),
					[this](int v) {cout << v+m_nData << endl;});
		}

		// 除b按引用传递外，其他均按值传递，输出：11 12 17
		{
			cout << "除b按引用传递外，其他均按值传递，输出：11 12 17" << endl;
			int a = 10;
			int b = 15;
			for_each(vctTemp.begin(), vctTemp.end(),
					[=, &b](int v) {cout << v+a << endl; b++;});
			cout << b << endl;
		}

		// 操作符重载函数参数按引用传递，输出：2 3
		{
			cout << "操作符重载函数参数按引用传递，输出：2 3" << endl;
			for_each(vctTemp.begin(), vctTemp.end(), [](int &v) {v++;});
			for_each(vctTemp.begin(), vctTemp.end(),
					[](int v) {cout << v << endl;});
		}

		// 空的Lambda表达式
		{
			cout << "空的Lambda表达式" << endl;
			[]() {}();
			[] {}();
		}

		cout << "TestLambda end ..." << endl;
	}

private:
	int m_nData;
};

int main(void) {
	shared_ptr<CTest> sp(new CTest());

	sp->TestLambda();
	return 0;
}
