#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> exchangeRateMap_;
	std::map<std::string, strign> inputFileMap_;

	void	parseData();
	void	parseInput(std::string& filename);
public:
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange& arg);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	std::ostream& operator<<(std::ostream& out);

	void	printMap(int map); // DEBUGGING

};

template <typename T>
std::string toString(const T& value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

#endif