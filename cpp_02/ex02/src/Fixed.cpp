#include "Fixed.hpp"

Fixed::Fixed() : rawNumberValue_(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called\n";
	rawNumberValue_ = fixed.rawNumberValue_;
	// or to get what's in the pdf:
	// *this = fixed ( This will call the operator= (Copy Assignment Operator) )
}

Fixed::Fixed(const int intNum)
{
	// std::cout << "Int constructor called\n";
	rawNumberValue_ = intNum << k_fractionalBits_;
}

Fixed::Fixed(const float floatNum)
{
	// std::cout << "Float constructor called\n";
	// 1 << _k_fractional bits is the code version of 2^_k_fractional (k_fractionalBits_)
	rawNumberValue_ = int(roundf(floatNum * (1 << k_fractionalBits_)));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
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
	// std::cout << "getRawBits member function called\n";
	return rawNumberValue_;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n";
	rawNumberValue_ = raw;
}

float Fixed::toFloat() const
{
	return (float(rawNumberValue_) / float(1 << k_fractionalBits_));
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> k_fractionalBits_);
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& num)
{
	Fixed fixed;
	fixed.setRawBits(rawNumberValue_ + num.getRawBits());
	return fixed;
}

Fixed Fixed::operator-(const Fixed& num)
{
	Fixed fixed;
	fixed.setRawBits(rawNumberValue_ - num.getRawBits());
	return fixed;
}

Fixed Fixed::operator*(const Fixed& num)
{
	Fixed fixed;
	fixed.setRawBits((rawNumberValue_ * num.getRawBits()) >> k_fractionalBits_);
	return fixed;
}

Fixed Fixed::operator/(const Fixed& num)
{
	Fixed fixed;
	fixed.setRawBits((rawNumberValue_ << k_fractionalBits_) / num.getRawBits());
	return fixed;
}

// Comparison Operators

bool Fixed::operator>(const Fixed& num) const
{
	if (*this == max(*this, num))
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& num) const
{
	if (*this == Fixed::min(*this, num))
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& num) const
{
	return (!(this->operator<(num)));
}

bool Fixed::operator<=(const Fixed& num) const
{
	return (!(this->operator>(num)));
}

bool Fixed::operator==(const Fixed& num) const
{
	if (this->getRawBits() == num.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& num) const
{
	return (!(this->operator==(num)));
}

Fixed& Fixed::operator++()
{
	rawNumberValue_++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed& Fixed::operator--()
{
	rawNumberValue_--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1.getRawBits() <= n2.getRawBits())
		return n1;
	return n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1.getRawBits() <= n2.getRawBits() )
		return n1;
	return n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1.getRawBits() >= n2.getRawBits() )
		return n1;
	return n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1.getRawBits() >= n2.getRawBits())
		return n1;
	return n2;
}
