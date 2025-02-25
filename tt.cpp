#include <iostream>
#include <cassert>
#include <chrono>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;

struct fibs_modulo_t
{
	int a_ = 0, b_ = 1, m_;

	fibs_modulo_t(int m) : m_{m} {}

	int next()
	{
		int tmp = a_;
		a_ = b_;
		b_ = (tmp + a_) % m_;
		return tmp;
	}
};

template <typename T>
void f(T &param){
	std::cout << param << std::endl;
};

int main()
{
	unsigned long long k = 0;
	int m = 0;
	std::cin >> k >> m;

	assert(k > 1);
	assert(m > 1);

	std::cout << "message struct " << std::endl;
	auto tstart = high_resolution_clock::now();
	fibs_modulo_t fm{m};
	for (unsigned long long i = 0; i < k; ++i)
		fm.next();
	auto tfin = high_resolution_clock::now();

	std::cout << duration_cast<milliseconds>(tfin - tstart).count() << std::endl;
	std::cout << "hello" << std::endl;
	std::cout << std::endl;

	int x1 = 4;
	int &&y = x1 + 1;
	std::cout << &x1 << " " << &y << std::endl; // 0xe0961ffaac 0xe0961ffaa8lllkk

	int &&z = std::move(x1);
	z = z + 1;
	y = y + 1;
	std::cout << x1 << " " << y << std::endl; // 5 6

	std::cout << std::endl;
	int x = 27;
	const int cx = x;
	const int &rx = x;
	f(x);
	f(cx);
	f(rx);
}
