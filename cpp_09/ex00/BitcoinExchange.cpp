#include "BitcoinExchange.hpp"

#include <fstream>

BitcoinExchange::BitcoinExchange(std::string filename)
{
	try
	{
		parseData();
		parseInput(filename);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "usage: ./btc <filename>" << std::endl;
		exit(EXIT_FAILURE);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& arg)
: exchangeRateMap_(arg.exchangeRateMap_)
, inputFileMap_(arg.inputFileMap_)
{
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	exchangeRateMap_ = rhs.exchangeRateMap_;
	inputFileMap_ = rhs.inputFileMap_;
	return *this;
}

std::string parseValue(const std::string& buffer)
{
	float value = strtof(buffer.substr(buffer.find(',') + 1).c_str(), NULL);
	if (errno == ERANGE)
		throw std::runtime_error("bad value");
	if (value == 0)
		return "Error: zero number";
	if (value < 0)
		return "Error: not a positive number.";
	if (value >= 1000)
		return "Error: too large a number";
	return toString<float>(value);
}

int	parseDate(std::string date)
{
	if (date.substr(0, date.find_first_of('-')).length() != 4)
		return BADINPUT;
	std::cout << date.substr(0, date.find_first_of('-')) << std::endl;
	exit(0);
	for (size_t i = 0; i < 2; i++)
	{
		date = date.substr(date.find_first_of('-') + 1);
		if (date.substr(0, date.find_first_of('-')).length() != 2)
			return BADINPUT;
	}
	int year, month, day;
	if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return BADINPUT;
	if (year < 2009)
		return BADYEAR;
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
	return 10000 * year + 100 * month + day;
}

void	BitcoinExchange::parseInput(std::string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("bad file");
	std::string buffer;
	while (std::getline(file, buffer))
	{
		std::string date = buffer.substr(0, buffer.find_first_of(' '));
		float value = strtof(buffer.substr(buffer.find_last_of(' ') + 1).c_str(), NULL);
		if (errno == ERANGE)
			throw std::runtime_error("bad value");
		std::pair<std::string, float> dateValue(date, value);
		inputFileMap_.insert(dateValue);
	}
}

void BitcoinExchange::parseData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
			throw std::runtime_error("bad file");
	std::string buffer;
	while (std::getline(file, buffer))
	{
		int date = parseDate(buffer.substr(0, buffer.find(',')));
		float value = strtof(buffer.substr(buffer.find(',') + 1).c_str(), NULL);
		if (errno == ERANGE)
			throw std::runtime_error("bad value");
		std::pair<int, float> dateValue(date, value);
		exchangeRateMap_.insert(dateValue);
	}
}

std::string setError(int err, const std::string& date)
{
	if (err == BADINPUT)
		return "Error: bad input => " + date;
	if (err == BADYEAR)
		return "Error: year less than 2009.";
	if (err == NEGATIVE)
		return "Error: not a positive number.";
	if (err == TOOBIG)
		return "Error: too large a number.";
	return "";
}

float BitcoinExchange::matchDate(int date)
{
	std::map<int, float>::iterator exchangeRateIt = exchangeRateMap_.lower_bound(date);
	if (exchangeRateIt == exchangeRateMap_.end())
		return exchangeRateMap_.rbegin()->second;
	if (exchangeRateIt->first == date)
		return exchangeRateIt->second;
	if (exchangeRateIt == exchangeRateMap_.begin())
		return exchangeRateIt->second;
	exchangeRateIt--;
	return exchangeRateIt->second;
}

std::map<int, float> BitcoinExchange::getExchangeRate() const
{
	return exchangeRateMap_;
}

std::map<std::string, float> BitcoinExchange::getInputFile() const
{
	return inputFileMap_;
}


std::ostream& operator<<(std::ostream& out, BitcoinExchange& rhs)
{
	std::map<std::string, float>::iterator	inputIt;
	
	std::map<std::string, float>	inputFileMap = rhs.getInputFile();

	if (inputFileMap.begin() == inputFileMap.end())
	{
		out << "Error: empty input" << std::endl;
		return out;
	}

	for (inputIt = inputFileMap.begin(); inputIt != inputFileMap.end(); inputIt++)
	{
		int date = parseDate(inputIt->first);
		if (date < 0)
		{
			out << setError(date, inputIt->first) << std::endl;
			continue;
		}
		float exchangeVal = rhs.matchDate(date);
			out << inputIt->first << " => " << inputIt->second
				<< " = " << inputIt->second * exchangeVal << std::endl;
	}
	return out;
}

// void	BitcoinExchange::printMap(int map)
// {
// 	if (map == 1)
// 	{
// 		std::map<std::string, float>::iterator it = exchangeRateMap_.begin();
// 		while (it != exchangeRateMap_.end())
// 		{
// 			std::cout << it->first << "," << it->second << std::endl;
// 			it++;
// 		}
// 	}
// 	else
// 	{
// 		std::map<std::string, float>::iterator it = inputFileMap_.begin();
// 		while (it != inputFileMap_.end())
// 		{
// 			std::cout << it->first << "," << it->second << std::endl;
// 			it++;
// 		}
// 	}
// }
