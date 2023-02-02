#include "ScalarConverter.hpp"

std::string ScalarConverter::literal_;

char ScalarConverter::charVal_;
int ScalarConverter::intVal_;
float ScalarConverter::floatVal_;
double ScalarConverter::doubleVal_;

ScalarConverter::type ScalarConverter::type_;


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

bool validInt(std::string literal)
{
	if (!isdigit(literal[0]))
		if (literal[0] == '-' || literal[0] == '+')
			literal.erase(0, 1); // Here I am erasing the sign because the next function just checks for digits
	if (literal.find_first_not_of("0123456789") != std::string::npos)
		return false;
	return true;
}

bool validDouble(std::string literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if (literal.find('.') != std::string::npos)
		literal.erase(literal.find('.'), 1);// Here I erase the first decimal point I find.
	if (validInt(literal))					// If the string now is not a valid int,
		return true;						// then there are more points in the string and it is invalid.
	return false;
}

bool validFloat(std::string literal)
{
	if (literal.back() == 'f')
		literal.pop_back();
	if (validDouble(literal)) // Checking for float input by removing the 'f' at the end and checking if it's a double
		return true;
	return false;
}

bool ScalarConverter::validInput()
{
	if (literal_.empty())
		return false;

	if (validInt(literal_))
		return (type_ = intType, true);
	
	if (literal_.size() == 1 && isprint(literal_[0]))	// Checking for char input (only displayable chars accepted)
		return (type_ = charType, true);
	
	if (validDouble(literal_))
		return (type_ = doubleType, true);
	
	if (validFloat(literal_))
		return (type_ = floatType, true);

	return false;
}

void ScalarConverter::outChar()
{
	std::cout << "char  : ";
	if (errno == ERANGE
		|| doubleVal_ < CHAR_MIN || doubleVal_ > CHAR_MAX
		|| isnan(doubleVal_))
		std::cout << "Impossible" << std::endl;
	else if (!isprint(charVal_))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << charVal_ << "'" << std::endl;
}

void ScalarConverter::outInt()
{
	std::cout << "int   : ";
	if (errno == ERANGE
		|| doubleVal_ < INT_MIN || doubleVal_ > INT_MAX
		|| isnan(doubleVal_))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << intVal_ << std::endl;
}

void ScalarConverter::outFloat()
{
	std::cout << "float : ";
	if (errno == ERANGE)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::fixed << floatVal_ << 'f' << std::endl;
}

void ScalarConverter::outDouble()
{
	std::cout << "double: ";
	if (errno == ERANGE)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::fixed << doubleVal_ << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	literal_ = literal;
	if (!validInput())
		throw std::runtime_error("Invalid input!");

	switch (type_)
	{
	long	int_l;

	case charType:
		charVal_ = literal_[0];
		intVal_ = static_cast<int>(charVal_);
		floatVal_ = static_cast<float>(charVal_);
		doubleVal_ = static_cast<double>(charVal_);
		break;
	case intType:
		int_l = strtol(literal_.c_str(), NULL, 10); {if (int_l < INT_MIN || int_l > INT_MAX) {errno = ERANGE;}}
		intVal_ = int_l;
		charVal_ = static_cast<char>(intVal_);
		floatVal_ = static_cast<float>(intVal_);
		doubleVal_ = static_cast<double>(intVal_);
		break;
	case floatType:
		floatVal_ = strtof(literal_.c_str(), NULL);
		charVal_ = static_cast<char>(floatVal_);
		intVal_ = static_cast<int>(floatVal_);
		doubleVal_ = static_cast<double>(floatVal_);
		break;
	case doubleType:
		doubleVal_ = strtod(literal_.c_str(), nullptr);
		intVal_ = static_cast<int>(doubleVal_);
		charVal_ = static_cast<char>(doubleVal_);
		floatVal_ = static_cast<float>(doubleVal_);
	default:
		break;
	}
	outChar();
	outInt();
	outFloat();
	outDouble();
}
