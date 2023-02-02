#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>

class ScalarConverter
{
private:
	static std::string	literal_;

	static char			charVal_;
	static int			intVal_;
	static float		floatVal_;
	static double		doubleVal_;
	
	static enum type {
		charType,
		intType,
		floatType,
		doubleType,
	}			type_;

	static bool validInput();
	static void	outChar();
	static void	outInt();
	static void	outFloat();
	static void	outDouble();

	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
public:
	~ScalarConverter();

	static void convert(std::string literal);
};


#endif
