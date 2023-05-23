#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>

#define BADINPUT	-1 // date is not valid
#define BADYEAR		-2 // year < 2009
#define NEGATIVE 	-3 // input number < 0
#define TOOBIG		-4 // input number > 1000

class BitcoinExchange
{
private:
	std::map<int, float>	exchangeRateMap_;
	const std::string		file_;

	void	parseData();
public:
	BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& arg);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	const std::string&	getFile() const;

	float	 matchDate(int date);
	void	printMap(); // DEBUGGING

};
std::ostream&	operator<<(std::ostream& out, BitcoinExchange& rhs);

template <typename T>
std::string toString(const T& value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

#endif