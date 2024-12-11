/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:17:18 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/11 17:36:47 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_is_full = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::SetData(void)
{
	char	input;

	if (this->_is_full == false)
	{
		std::cout << "Contact number " << this->_index + 1 << std::endl;
		if (this->_contacts[this->_index].SetContact() == true)
		{
			if (this->_index == 7)
				this->_is_full = true;
			else
				this->_index++;
		}
	}
	else
	{
		std::cout << "The phonebook is full!" << std::endl;
		std::cout << "For deletion of the 1st existing contact";
		std::cout << " and adding the new one as the last press 'y'." << std::endl;
		std::cout << "For going back to the main menu press 'n'." << std::endl;
		std::cin >> input;
		if (std::cin.eof() == true)
		{
			std::cout << "\033[31mCtrl - D pressed - exiting the phone book.\033[0m" << std::endl;
			std::exit(0);
		}
		else if (input == 'y')
		{
			for (int i = 1; i < 8; i++)
				this->_contacts[i - 1] = this->_contacts[i];
			std::cout << "Contact number " << this->_index + 1 << std::endl;
			this->_contacts[this->_index].SetContact();
		}
		else if (input == 'n')
			std::cout << "Going back to the main menu" << std::endl;
	}
}

void	PhoneBook::GetData() const
{
//	int	index;
	
	if (this->_index == 0)
		std::cout << "\033[31mThe phone book is empty\033[0m" << std::endl;
	else
	{
		char	input;
		while (42)
		{
			std::cout << "Press a button from '1' to '8' to show the contact assigned to that number";
			std::cout << " or 'n' to go back to the main menu" << std::endl;
			std::cin >> input;
			if (std::cin.eof() == true)
			{
				std::cout << "\033[31Ctrl - D pressed - exiting the phone book!\033[0m" << std::endl;
				std::exit(0);
			}
			else if (input == 'n')
			{
				std::cout << "Going back to the main menu" << std::endl;
				break;
			}
			else if ((input < '0' || input > '8') && input != 'n')
			{
				std::cout << "Error: out of range!" << std::endl;
				std::cout << "Press a button from '1' to '8' to show the contact assigned to that number";
				std::cout << " or 'n' to go back to the main menu" << std::endl;
			}
			else
			{
				std::cout << "|-------------------------------------------|" << std::endl;
				std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
				std::cout << "|----------|----------|----------|----------|" << std::endl;
				this->_contacts[input - 48 - 1].GetContact(input - 48);
				std::cout << "|----------|----------|----------|----------|" << std::endl;
			}
		}
		if (index != 'n')
		{
			std::cout << "Error: fatal!!!" << std::endl;
			exit(1);
		}
		else
			return;
}
