#include "Fixed.hpp"

Fixed::Fixed() : rawNumberValue_(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	rawNumberValue_ = fixed.rawNumberValue_;
	// or to get what's in the pdf:
	// *this = fixed (This will call the operator=() (Copy Assignment Operator))
}

Fixed::Fixed(const int intNum)
{
	std::cout << "Int constructor called\n";
	rawNumberValue_ = intNum << k_fractionalBits_;
}

Fixed::Fixed(const float floatNum)
{
	std::cout << "Float constructor called\n";
	// 1 << k_fractionalBits_ is the code version of 2^8 (k_fractionalBits_)
	rawNumberValue_ = int(roundf(floatNum * (1 << k_fractionalBits_)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	rawNumberValue_ = fixed.rawNumberValue_;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return rawNumberValue_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	rawNumberValue_ = raw;
}

float Fixed::toFloat() const
{
	return float(rawNumberValue_) / float(1 << k_fractionalBits_);
}

int Fixed::toInt() const
{
	return rawNumberValue_ >> 8;
}
