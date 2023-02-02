#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int 				rawNumberValue_;
	static const int	k_fractionalBits_ = 8;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	Fixed(const int intNum);
	Fixed(const float floatNum);
	~Fixed();

	Fixed& operator=(const Fixed& fixed);
	
	// Arithmetic Operators
	Fixed operator*(const Fixed& num);
	Fixed operator/(const Fixed& num);
	Fixed operator+(const Fixed& num);
	Fixed operator-(const Fixed& num);
	
	// Comparison Operators
	bool operator>(const Fixed& num) const;
	bool operator<(const Fixed& num) const;

	bool operator>=(const Fixed& num) const;
	bool operator<=(const Fixed& num) const;

	bool operator==(const Fixed& num) const;
	bool operator!=(const Fixed& num) const;

	// Increment / Decrement Operators
	Fixed& operator++();	// Prefix
	Fixed operator++(int);	// Postfix
	Fixed& operator--();	// Prefix
	Fixed operator--(int);	// Postfix

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
	
	static Fixed& min(Fixed& n1, Fixed& num);
	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);
	static const Fixed& max(const Fixed& n1, const Fixed& n2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
