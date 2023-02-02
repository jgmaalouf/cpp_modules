#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*current_time;
	char		buffer[80];

	time(&rawtime);
	current_time = localtime(&rawtime);
	std::strftime(buffer, 80, "%G%m%d_%H%M%S", current_time);

	std::cout << "[" << buffer << "] ";

}

int Account::checkAmount(void) const
{
	return (_amount);
}

Account::Account(int initial_deposit)
{
	static int i;

	_accountIndex = i;
	_nbAccounts = i + 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "created"
				<< std::endl;
	i++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "closed"
				<< std::endl;
	_nbAccounts--;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool display_withdrawal(int account_index, int amount, int withdrawal, int nb_withdrawals, bool ret)
{
	std::cout	<< "index:" << account_index << ";"
				<< "p_amount:" << amount << ";";
	if (ret == true)
		std::cout	<< "withdrawal:" << withdrawal << ";"
					<< "nb_deposits:" << nb_withdrawals;
	else
		std::cout << "withdrawal:refused";
	std::cout << std::endl;
	return ret;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout	<< "withdrawal:" << "refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
	}
	std::cout	<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}
