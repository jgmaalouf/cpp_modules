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

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
