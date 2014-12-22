// bind example
#include <iostream>     // std::cout
#include <functional>   // std::bind
#include <memory>
using namespace std;
// a function: (also works with function object: std::divides<double> my_divide;)
double my_divide(double x, double y) {
	return x / y;
}

struct MyPair {
	double a, b;
	double multiply() {
		return a * b;
	}
};
class TAdd {
public:
	TAdd() {
		std::cout << " TAdd " << this << '\n';
	}
	~TAdd() {
		std::cout << "~TAdd " << this << '\n';
	}
	int Add(int x, int y) {
		std::cout << "Add..." << x << ", " << y << '\n'; // 5
		return x + y;
	}
};

int main() {
	{
		TAdd tAdd;
		TAdd *p = new TAdd();
		shared_ptr<TAdd> q(p);
		bind(&TAdd::Add, tAdd, 2, 3)();
		bind(&TAdd::Add, p, 20, 30)();
		bind(&TAdd::Add, q, 200, 300)();
	}
	{
		using namespace std::placeholders;
		// adds visibility of _1, _2, _3,...

		// binding functions:
		auto fn_five = std::bind(my_divide, 10, 2); // returns 10/2
		std::cout << fn_five() << '\n'; // 5

		auto fn_half = std::bind(my_divide, _1, 2); // returns x/2
		std::cout << fn_half(10) << '\n'; // 5

		auto fn_invert = std::bind(my_divide, _2, _1); // returns dy/x
		std::cout << fn_invert(10, 2) << '\n'; // 0.2

		auto fn_rounding = std::bind<int>(my_divide, _1, _2); // returns int(x/y)
		std::cout << fn_rounding(10, 3) << '\n'; // 3

		MyPair ten_two { 10, 2 };

		// binding members:
		auto bound_member_fn = std::bind(&MyPair::multiply, _1); // returns x.multiply()
		std::cout << bound_member_fn(ten_two) << '\n'; // 20

		auto bound_member_data = std::bind(&MyPair::a, ten_two); // returns ten_two.a
		std::cout << bound_member_data() << '\n'; // 10
	}
	return 0;
}
