/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:17:18 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/10 16:19:46 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_Index = 0;
	this->_Full = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::SetInformation(void)
{
	std::string Input;
	if (this->
