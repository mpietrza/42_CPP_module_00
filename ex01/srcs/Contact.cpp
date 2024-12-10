/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:01:50 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/10 16:05:59 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Contact.hpp"

/**
 * @brief Fields name for the contact
 * 
 * @param 0 First Name
 * @param 1 Last Name
 * @param 2 Nickname
 * @param 3 Phone Number
 * @param 4 Darkest Secret
 */
std::string Contact::_FieldsName[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

/**
 * @brief Construct a new Contact:: Contact object
 */
Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->_Information[i] = std::string();
		return;
}

/**
 * @brief Destroy the Contact:: Contact object
 */
Contact::~Contact()
{
	return;
}

/**
 * @brief Set the Contact object
 * 
 * @return true if all fields are filled
 */
bool	Contact::SetContact()
{
	for (int i = FirstName; i<=DarkestSecret; i++)
	{
		std::cout << "Please enter the " << Contact::_FieldsName[i] << ":\n+";
		while (!(std::getline(std::cin, this->_Information[i])) || this->_Information[i].length() == 0)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Ctrl - D pressed - exiting the phone book." << std::endl;
				std::exit(0);
			}
			else if (this->_Information[i].length() == 0)
			{
				this->_Information[i].clear();
				std::cout << "\033[31mAll fields mustn't be blank\033[0m" << std::endl;
				std::cout << "Please provide the "<< Contact::_FieldsName[i] << ":\n+";
			}
		}
	}
	std::cout << "\033[32mContact data added successfully!\033[0m" << std::endl;
	return (true);
}

/**
 * @brief Get the Contact object
 * 
 * @param Index Index of the contact
 */
void	Contact::GetContact(int Index) const
{
	std::cout << "|" << std::setw(10) << Index;
	for (int i = FirstName; i <=  Nickname; i++)
	{
		std::cout << "|";
		if (this->_Information[i].length() > 10)
			std::cout << this->_Information[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_Information[i];
	}
	std::cout << "|" << std::endl;
}	
