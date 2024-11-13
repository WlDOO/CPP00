/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:03:37 by najeuneh          #+#    #+#             */
/*   Updated: 2024/11/13 15:25:46 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int  Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int		Account::checkAmount(void) const
{
	return this->_amount;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->checkAmount() < withdrawal)
	{
		std::cout <<" index:" << this->_accountIndex << ";p_amount:"
			  	  << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	std::cout << " index:" << this->_accountIndex << ";p_amount:"
			  << this->_amount + withdrawal << ";withdrawal:"
			  << withdrawal << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << " index:" << this->_accountIndex << ";p_amount"
			  << this->_amount - deposit << ";deposit:"
			  << deposit << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this-> _accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:"
			  << getNbAccounts()
			  << ";total:"
			  << getTotalAmount()
			  << ";deposit:"
			  << getNbDeposits()
			  << ";withdrawals:"
			  << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) :
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	_accountIndex = getNbAccounts();
	 _nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amout:"
			  << this->_amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	struct tm* local_time = std::localtime(&now);
	std::cout << "["
			  << local_time->tm_year + 1900;
	if (local_time->tm_mon + 1 < 10)
	{
		std::cout << 0;
		std::cout << local_time->tm_mon + 1;
	}
	else
		std::cout << local_time->tm_mon + 1;
	if (local_time->tm_mday < 10)
	{
		std::cout << 0;
		std::cout << local_time->tm_mday;
	}
	else
		std::cout << local_time->tm_mday;
	std::cout << "_";
	if (local_time->tm_hour < 10)
	{
		std::cout << 0;
		std::cout << local_time->tm_hour;
	}
	else
		std::cout << local_time->tm_hour;
	if (local_time->tm_min < 10)
	{
		std::cout << 0;	
		std::cout << local_time->tm_min;
	}
	else
		std::cout << local_time->tm_min;
	if (local_time->tm_sec < 10)
	{
		std::cout << 0;
		std::cout << local_time->tm_sec;
	}
	else
		std::cout<< local_time->tm_sec;
	std::cout << "]";
	
}

