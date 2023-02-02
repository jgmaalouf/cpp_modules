#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int 				numberValue_;
	static const int	k_fractionalBits_ = 8;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();

	Fixed& operator=(const Fixed& fixed);

	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif
