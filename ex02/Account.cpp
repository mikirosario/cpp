/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 22:59:55 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/03 15:15:41 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Account.hpp"

Account::Account(int initial_deposit) :
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	this->_nbAccounts--;
	std::cout << " index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "closed" << std::endl;
}

int			Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int			Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int			Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int			Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void		Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";"
			<< "total:" << _totalAmount << ";"
			<< "deposits:" << _totalNbDeposits << ";"
			<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	int	p_amount;
	
	p_amount = this->_amount;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int			Account::checkAmount(void) const
{
	return (this->_amount);
}

void		Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	namespace time = std::chrono;
	
	tm utc_tm;
	std::time_t current_time;
	
	current_time = time::system_clock::to_time_t(time::system_clock::now());
	utc_tm = *localtime(&current_time);
	std::cout << std::setfill('0') << "[" << utc_tm.tm_year + 1900
			<< std::setw(2) << utc_tm.tm_mon
			<< std::setw(2) << utc_tm.tm_mday << "_"
			<< std::setw(2) << utc_tm.tm_hour
			<< std::setw(2) << utc_tm.tm_min
			<< std::setw(2) << utc_tm.tm_sec << "]";
}



int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// int	main(void)
// {
// 	typedef std::vector<Account::t>	accounts_t;
// 	typedef std::vector<int>	  ints_t;
// 	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;


// 	int	const	amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
// 	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
// 	accounts_t				accounts( amounts, amounts + amounts_size );
// 	accounts_t::iterator	acc_begin	= accounts.begin();
// 	accounts_t::iterator	acc_end		= accounts.end();

// 	int	const			d[]	= { 5, 765, 564, 2, 87, 23, 9, 20 };
// 	size_t const		d_size( sizeof(d) / sizeof(int) );
// 	ints_t				deposits( d, d + d_size );
// 	ints_t::iterator	dep_begin	= deposits.begin();
// 	ints_t::iterator	dep_end		= deposits.end();

// 	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
// 	size_t const		w_size( sizeof(w) / sizeof(int) );
// 	ints_t				withdrawals( w, w + w_size );
// 	ints_t::iterator	wit_begin	= withdrawals.begin();
// 	ints_t::iterator	wit_end		= withdrawals.end();



// 	Account::displayAccountsInfos();
// 	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

// 	for ( acc_int_t it( acc_begin, dep_begin );
// 		  it.first != acc_end && it.second != dep_end;
// 		  ++(it.first), ++(it.second) ) {

// 		(*(it.first)).makeDeposit( *(it.second) );
// 		}

// 	Account::displayAccountsInfos();
// 	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

// 	for ( acc_int_t it( acc_begin, wit_begin );
// 		  it.first != acc_end && it.second != wit_end;
// 		  ++(it.first), ++(it.second) ) {

// 		(*(it.first)).makeWithdrawal( *(it.second) );
// 	}

// 	Account::displayAccountsInfos();
// 	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

// 	return (1);
// }