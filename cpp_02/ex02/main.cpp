#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(a);
	c.setRawBits(2);
	a.setRawBits(2);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << (Fixed(42.21f) / Fixed(2.4f)) << std::endl;
	std::cout << (Fixed(42.21f) + Fixed(2.79f)) << std::endl;
	std::cout << (Fixed(42.21f) - Fixed(2.21f)) << std::endl;

	std::cout << (b > a) << std::endl;
	std::cout << (b < a) << std::endl;

	std::cout << (b >= a) << std::endl;
	std::cout << (b <= a) << std::endl;

	std::cout << (b == a) << std::endl;
	std::cout << (b != a) << std::endl;
	std::cout << (++++c == a) << std::endl;

	return 0;
}