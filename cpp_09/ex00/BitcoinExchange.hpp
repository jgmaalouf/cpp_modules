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
	std::map<int, float>			exchangeRateMap_;
	std::map<std::string, float>	inputFileMap_;


	void	parseData();
	void	parseInput(std::string& filename);
public:
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange& arg);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	std::map<int, float> 			getExchangeRate() const;
	std::map<std::string, float> 	getInputFile() const;

	float	 matchDate(int date);
	void	printMap(int map); // DEBUGGING

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