#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>

#define BADINPUT  -1 // input is badly formatted
#define BADYEAR   -2 // year < 2009
#define NEGATIVE  -3 // input number < 0
#define TOOBIG    -4 // input number > 1000
#define OVFLOW    -5 // input number overflowed
#define BADFILE   -6 // file
#define BADFORMAT -7 // format unaccepted

class BitcoinExchange
{
private:
	std::map<int, float> exchangeRateMap_;
	std::string          file_;

	void parseData();
	float matchDate(int date);
	const std::string& getFile() const;
public:
	BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& arg);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& rhs);

	void calculateRates();
};

/* Utils */

void validateLine(const std::string& buffer);
int  parseDate(std::string date);
void setError(int err, const std::string& date);
void setError(int err);
bool prepInputLine(std::string& buffer);
#endif