#include "Account.hpp"
#include <iostream>
#include <iomanip>

Account::Account (int initial_deposit) : _accountIndex(Account::_nbAccounts),
 _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ) {
	time_t now;

    now = time(0);
    struct tm *tm = localtime(&now);
    std::cout<<std::put_time(tm, "[%Y%m%d_%H%M%S] ");
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() <<
	";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() <<std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount <<
	";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" 
	<< this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int p_amount = this->_amount;

	if (this->checkAmount() < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount <<
		";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount <<
		";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" 
		<< this->_nbWithdrawals << std::endl;
		return (true);
	}
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals <<std::endl;
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
