# include <iostream>
# include <iomanip>
# include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void _display_time_stamp(void) {
	time_t	now = time(0);
	tm		*current = localtime(&now);

	std::cout << "[";
	std::cout << current->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << current->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << current->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << current->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << current->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << current->tm_sec;
	std::cout << "] ";
}

Account::Account(void) {
	_display_time_stamp();

	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std:: cout << "created" << std::endl;
}

Account::Account(int initial_deposit) {
	_display_time_stamp();

	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std:: cout << "created" << std::endl;
}

Account::~Account(void) {
	_display_time_stamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_display_time_stamp();

	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std:: cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	_display_time_stamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std:: cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
	_display_time_stamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	this->_nbDeposits ++;
	_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std:: cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount( void ) const {
	return this->_amount;
}

bool Account::makeWithdrawal( int wthdrawal ) {
	_display_time_stamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";

	if (checkAmount() < wthdrawal)
	{
		std:: cout << "refused" << std::endl;
		return false;
	}

	this->_nbWithdrawals ++;
	_totalNbWithdrawals++;
	this->_amount -= wthdrawal;
	_totalAmount -= wthdrawal;

	std::cout << wthdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std:: cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}
