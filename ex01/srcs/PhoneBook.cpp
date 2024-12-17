/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:17:18 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/17 18:58:05 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"

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

void PhoneBook::SetData(void)
{
	std::string input;

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
		std::cout << "\033[31mThe phonebook is full!" << std::endl;
		std::cout << "For deletion of the 1st existing contact"
				  << " and adding the new one as the first press 'y'." << std::endl;
		std::cout << "For going back to the main menu press 'n'.\033[0m" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl - D pressed - exiting the phone book." << std::endl;
			std::exit(0);
		}
		else if (input.compare("y") == 0)
		{
			std::cout << "Contact number 1" << std::endl;
			this->_contacts[0].SetContact();
		}
		else if (input.compare("n") == 0)
			std::cout << "Going back to the main menu" << std::endl;
		else
			std::cout << "\033[31mError: unknown command!\033[0m" << std::endl;
		input.clear();
	}
}

void PhoneBook::GetData() const
{
	if (this->_index == 0)
	{
		std::cout << "\033[31mThe phone book is empty\033[0m" << std::endl;
	}
	else
	{
		std::string input;
		while (true)
		{
			std::cout << "|-------------------------------------------|" << std::endl;
			std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			if (this->_contacts[0].IsEmpty() == false)
			{
				for (int i = 0; i <= this->_index; i++)
					this->_contacts[i].GetContact(i + 1, true);
			}
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			std::cout << "Press a button from '1' to '8' to show the contact assigned to that number"
					  << " or 'n' to go back to the main menu" << std::endl;
			std::getline(std::cin, input);
			if (std::cin.eof() == true)
			{
				std::cout << "\033[1;34mCtrl - D pressed - exiting the phone book.\033[0m" << std::endl;
				std::exit(0);
			}
			else if (input.compare("n") == 0)
			{
				std::cout << "\033[1;33mGoing back to the main menu\033[0m" << std::endl;
				break;
			}
			else if (((input[0] < '1' || input[0] > '8') && input[0] != 'n') || input[1] != '\0')
				std::cout << "\033[31mError: out of range!\033[0m" << std::endl;			
			else if (this->_contacts[input[0] - 48 - 1].IsEmpty())
				std::cout << "\033[31mError: contact is empty!\033[0m" << std::endl;
			else
			{
				this->_contacts[input[0] - 48 - 1].GetContact(input[0] - 48, false);
				break;
			}
		}
		input.clear();
	}
}

void	PhoneBook::PrintInstruction() const
{
	std::cout << "\033[1;36m|---------Awesome phone book----------|\033[0m" << std::endl;
	std::cout << "To add a new contact type \033[1;37;1m'ADD'\033[0m." << std::endl;
	std::cout << "To search for a contact type \033[1;37;1m'SEARCH'\033[0m." << std::endl;
	std::cout << "To exit the phone book type \033[1;37;1m'EXIT'\033[0m." << std::endl;
}