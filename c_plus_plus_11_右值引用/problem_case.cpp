#include <iostream>
#include <vector>
using namespace std;

class obj {
public:
	obj() {
		cout << ">> create obj " << endl;
	}
	obj(const obj& other) {
		cout << ">> copy create obj " << endl;
	}
};

vector<obj> foo() {
	vector<obj> c;
	c.push_back(obj());

	cout << "---- exit foo ----" << endl;
	return c;
}

int main() {
	vector<obj> k;
	k = foo();

//	vector<obj> j = foo();

}
