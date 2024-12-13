/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:33 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/13 17:21:20 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * Constructor
 *
 * @param initial_deposit Initial deposit
 * @return void
 */
Account::Account(int initialDeposit) : _accountIndex(_nbAccounts++), 
	_amount(initialDeposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initialDeposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";created" << std::endl;
}

/**
 * Destructor
 *
 * @param void
 * @return void
 */
~Account::Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";closed" << std::endl;
}

/**
 * @brief Make a deposit to the account
 *
 * @param deposit The amount to deposit
 * @return void
 */
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_totalAmount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @brief Make a withdrawal from the account
 *
 * @param withdrawal The amount to withdraw
 * @return bool True if the withdrawal was successful, false otherwise
 */
 bool	Account::makeWithdrawal(int withdrawal)
 {
	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
			  << ";withdrawal:" << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
 }

 /**
 * @brief Get the actual state of the account
 *
 * @return void
 */
 void	Account::displayStatus() const
 {
	 _displayTimestamp();
	 std::cout << "index:" << _accountIndex << ";amount:" << _amount
			   << ";deposits:" << _nbDeposits
	 		   << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/**
 * @brief Display the actual state of all accounts
 * 
 * @return void
 */
 void	Account::displayAccountInfos()
 {
	 _displayTimestamp();
	 std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
	 		   << ";deposits:" << _totalNbDeposits
			   << ";withdrawals:" << _totalNbWithdrawals << std::endl;
 }

 /**
 * @brief Display the timestamp
 * 
 * @return void
 */
 void	Account::_displayTimestamp()
 {
	 std::time_t	t = std::time(nullptr);
	 std::tm		*now = std::localtime(&t);
	 
	 std::cout << "[" 
	 		   << (now->tm_year + 1900)
	 		   << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
			   << std::setw(2) << std::setfill('0') << now->tm_mday
			   << "_"
			   << std::setw(2) << std::setfill('0') << now->tm_hour
			   << std::setw(2) << std::setfill('0') << now->tm_min
			   << std::setw(2) << std::setfill('0') << now->tm_sec
			   << "] ";
 }
