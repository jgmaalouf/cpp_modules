#include "BitcoinExchange.hpp"

#include <fstream>

BitcoinExchange::BitcoinExchange(const std::string& filename)
: file_(filename)
{
	try
	{
		parseData();
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
, file_(arg.file_)
{
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	exchangeRateMap_ = rhs.exchangeRateMap_;
	return *this;
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
		return "Error: year less than 2009 => " + date;
	return "";
}

std::string setError(int err)
{
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


const std::string& BitcoinExchange::getFile() const
{
	return file_;
}

std::pair<int, float> parseDateValue(std::string& line)
{
	int date = parseDate(line.substr(0, line.find_first_of(' ')));
	float value = strtof(line.substr(line.find_last_of(' ') + 1).c_str(), NULL);
	if (errno == ERANGE)
		throw std::runtime_error("bad value");
	std::pair<int, float> dateValue(date, value);
	return dateValue;
}

std::ostream& operator<<(std::ostream& out, BitcoinExchange& rhs)
{
	try
	{
		std::ifstream file(rhs.getFile());
		if (!file.is_open())
			throw std::runtime_error("bad file");
		std::string buffer;
		while (std::getline(file, buffer))
		{
			std::string dateStr = buffer.substr(0, buffer.find_first_of(' '));
			std::pair<int, float> dateValue = parseDateValue(buffer);
			if (dateValue.first < 0)
			{
				out << setError(dateValue.first, dateStr) << std::endl;
				continue;
			}
			if (dateValue.second < 0)
				out << setError(NEGATIVE) << std::endl;
			else if (dateValue.second > 1000)
				out << setError(TOOBIG) << std::endl;
			else
			{
				float exchangeVal = rhs.matchDate(dateValue.first);
					out << dateStr << " => " << dateValue.second
						<< " = " << dateValue.second * exchangeVal << std::endl;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return out;
}

void	BitcoinExchange::printMap()
{
	std::map<int, float>::iterator it = exchangeRateMap_.begin();
	while (it != exchangeRateMap_.end())
	{
		std::cout << it->first << "," << it->second << std::endl;
		it++;
	}
}
