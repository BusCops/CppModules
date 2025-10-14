#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account :: _nbAccounts = 0;
int Account :: _totalAmount = 0;
int Account :: _totalNbDeposits = 0;
int Account :: _totalNbWithdrawals = 0;

void	Account :: _displayTimestamp( void )
{
	std :: time_t t;
	tm	*ltm;
	char	buff[19];

	t = time(NULL);
	ltm = localtime(&t);
	strftime(buff, 19, "[%Y%m%d_%H%M%S] ", ltm);
	std :: cout << buff;
}

int	Account :: getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account :: getTotalAmount( void )
{
	return _totalAmount;
}

int	Account :: getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account :: getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

Account :: Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount = getTotalAmount() + initial_deposit;
	_accountIndex = getNbAccounts();
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std :: endl;
}

void	Account :: displayAccountsInfos( void )
{
	_displayTimestamp();
	std :: cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std :: endl; 
}

void	Account :: displayStatus( void ) const
{
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std :: endl; 
}

void	Account :: makeDeposit( int deposit )
{
	int	Pamount;

	Pamount = _amount;
	_amount = deposit + _amount;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";p_amount:" << Pamount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std :: endl; 
}

int		Account :: checkAmount( void ) const
{
	return 0;
}

bool	Account :: makeWithdrawal( int withdrawal )
{
	int	Pamount;
	
	if (_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std :: cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << "refused" << std :: endl;
		return false;
	}
	Pamount = _amount;
	_amount = _amount - withdrawal;
	_totalAmount = _totalAmount - withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";p_amount:" << Pamount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std :: endl; 
	return true;
}

Account :: ~Account( void )
{
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std :: endl;
}