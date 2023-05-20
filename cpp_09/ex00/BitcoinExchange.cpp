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

std::string parseDate(const std::string& buffer)
{
	// Convert date to a numerical value so you can compare and find the closest lowest value when needed
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

void	BitcoinExchange::parseInput(std::string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("bad file");
	std::string buffer;
	while (std::getline(file, buffer))
	{
		std::string date = parseDate(buffer);
		float value = strtof(buffer.substr(buffer.find(',') + 1).c_str(), NULL);
		if (errno == ERANGE)
			throw std::runtime_error("bad value");
		std::pair<std::string, float> dateValue(date, value);
		exchangeRateMap_.insert(dateValue);
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
		std::string date = buffer.substr(0, buffer.find(','));
		float value = strtof(buffer.substr(buffer.find(',') + 1).c_str(), NULL);
		if (errno == ERANGE)
			throw std::runtime_error("bad value");
		std::pair<std::string, float> dateValue(date, value);
		exchangeRateMap_.insert(dateValue);
	}
}

// std::ostream& BitcoinExchange::operator<<(std::ostream& out)
// {

// }

void	BitcoinExchange::printMap(int map)
{
	if (map == 1)
	{
		std::map<std::string, float>::iterator it = exchangeRateMap_.begin();
		while (it != exchangeRateMap_.end())
		{
			std::cout << it->first << "," << it->second << std::endl;
			it++;
		}
	}
	else
	{
		std::map<std::string, float>::iterator it = inputFileMap_.begin();
		while (it != inputFileMap_.end())
		{
			std::cout << it->first << "," << it->second << std::endl;
			it++;
		}
	}
}
