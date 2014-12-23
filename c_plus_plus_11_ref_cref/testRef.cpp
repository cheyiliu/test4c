// ref example
#include <iostream>     // std::cout
#include <functional>   // std::ref
// g++ testRef.cpp -o testRef -std=c++11

int main() {
	int foo(10);

	auto bar = std::ref(foo);
	auto cbar = std::cref(foo);

	++bar;
//	++cbar;//error, const reference
	++foo;

	std::cout << foo << '\n';

	return 0;
}
