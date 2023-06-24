#include "BitcoinExchange.hpp"

void validateLine(const std::string& buffer)
{
	size_t commaCount = 0;
	size_t dashCount = 0;
	size_t size = buffer.size();
	for (size_t i = 0; i < size; i++)
	{
		if (buffer[i] == ',')
			commaCount++;
		else if (buffer[i] == '-')
			dashCount++;
		if (isdigit(buffer[i]) || buffer[i] == '-'
			|| buffer[i] == ',' || buffer[i] == '.')
			continue;
		throw std::runtime_error("bad data file");
	}
	if (commaCount != 1 || dashCount != 2)
		throw std::runtime_error("bad data file");
}

int	parseDate(std::string date)
{
	std::string dateCpy = date;
	if (dateCpy.substr(0, dateCpy.find_first_of('-')).length() != 4)
		return BADINPUT;
	for (size_t i = 0; i < 2; i++)
	{
		dateCpy = dateCpy.substr(dateCpy.find_first_of('-') + 1);
		if (dateCpy.substr(0, dateCpy.find_first_of('-')).length() != 2)
			return BADINPUT;
	}
	int year, month, day;
	if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
	{
		return BADINPUT;
	}
	if (month < 1 || month > 12)
		return BADINPUT;
	if (day < 0 || day > 31)
		return BADINPUT;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			return BADINPUT;
	if (month == 2 )
	{
		if (year % 4 == 0) // leap year
		{
			if (day > 29)
				return BADINPUT;
		}
		else if (day > 28)
			return BADINPUT;
	}
	if (year < 2009)
		return BADYEAR;
	return 10000 * year + 100 * month + day;
}

void setError(int err, const std::string& date)
{
	if (err == BADINPUT)
		std::cout << "Error: bad input => " + date << std::endl;
	else if (err == BADYEAR)
		std::cout << "Error: year less than 2009 => " + date << std::endl;
}

void setError(int err)
{
	if (err == NEGATIVE)
		std::cout << "Error: not a positive number." << std::endl;
	else if (err == TOOBIG)
		std::cout << "Error: too large a number." << std::endl;
	else if (err == OVFLOW)
		std::cout << "Error: number overflowed." << std::endl;
	else if (err == BADFILE)
		std::cout << "Error: bad file." << std::endl;
	else if (err == BADFORMAT)
		std::cout << "Error: unaccepted format." << std::endl;
}

bool prepInputLine(std::string& buffer)
{
	buffer.erase(std::remove_if(buffer.begin(), buffer.end(), isspace), buffer.end()); // Removes all spaces from line
	size_t bufferSize = buffer.size();
	size_t dashCount = 0;
	size_t pipeCount = 0;
	for (size_t i = 0; i < bufferSize; i++)
	{
		if (buffer[i] == '-')
			dashCount++;
		else if (buffer[i] == '|')
			pipeCount++;

		if (isdigit(buffer[i]) || buffer[i] == '-'
			|| buffer[i] == '|' || buffer[i] == '.')
			continue;
		return false;
	}
	if (dashCount < 2 || pipeCount != 1)
		return false;
	return true;
}
