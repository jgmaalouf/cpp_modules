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
	file_ = rhs.file_;
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
	if (commaCount != 1)
		throw std::runtime_error("bad data file");
	if (dashCount != 2)
		throw std::runtime_error("bad data file");

}

void BitcoinExchange::parseData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("bad file");
	std::string buffer;
	std::getline(file, buffer);
	if (buffer != "date,exchange_rate")
		throw std::runtime_error("unaccepted .csv");

	while (std::getline(file, buffer))
	{
		validateLine(buffer);

		size_t commaPos = buffer.find(',');

		int date = parseDate(buffer.substr(0, commaPos));
		if (date < 0)
			throw std::runtime_error("bad data file");

		float value = strtof(buffer.substr(commaPos + 1).c_str(), NULL);
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
	size_t space = line.find_first_of(' ');
	if (space == std::string::npos)
		throw std::runtime_error("bad formatting");

	int date = parseDate(line.substr(0, space));
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
