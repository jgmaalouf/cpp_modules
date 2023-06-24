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
	size_t pipePos = line.find('|');
	std::string dateStr = line.substr(0, pipePos);

	int date = parseDate(dateStr);
	float value = strtof(line.substr(pipePos + 1).c_str(), NULL);

	if (date < 0)
		setError(date, dateStr);
	else if (errno == ERANGE)
		setError(OVFLOW);
	else if (value < 0)
		setError(NEGATIVE);
	else if (value > 1000)
		setError(TOOBIG);
	std::pair<int, float> dateValue(date, value);
	return dateValue;
}

void BitcoinExchange::calculateRates()
{
	std::ifstream file(getFile());
	if (!file.is_open())
		return setError(BADFILE);

	std::string buffer;
	std::getline(file, buffer);
	if (buffer != "date | value")
		return setError(BADFORMAT);
	while (std::getline(file, buffer))
	{
		if (!prepInputLine(buffer))
		{
			setError(BADINPUT, buffer);
			continue;
		}
		std::pair<int, float> dateValue = parseDateValue(buffer);
		if (dateValue.first < 0 || dateValue.second < 0 || dateValue.second > 1000)
			continue;

		std::string dateStr = buffer.substr(0, buffer.find('|'));
		float exchangeVal = matchDate(dateValue.first);
		std::cout << dateStr << " => " << dateValue.second
			<< " = " << dateValue.second * exchangeVal << std::endl;
	}
}
