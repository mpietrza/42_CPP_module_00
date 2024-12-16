/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:01:50 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/16 16:48:37 by mpietrza         ###   ########.fr       */
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
std::string Contact::_NameOfField[5] =
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
		this->_data[i] = std::string();
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
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Please enter the " << Contact::_NameOfField[i] << ": ";
		while (!(std::getline(std::cin, this->_data[i])) || this->_data[i].length() == 0)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "\033[1;34mCtrl - D pressed - exiting the phone book.\033[0m" << std::endl;
				std::exit(0);
			}
			else if (this->_data[i].length() == 0)
			{
				this->_data[i].clear();
				std::cout << "\033[31mAll fields mustn't be blank\033[0m" << std::endl;
				std::cout << "Please provide the "<< Contact::_NameOfField[i] << ": ";
			}
			else
			{
				std::cout << "\033[31mError: fatal!!!\033[0m" << std::endl;
				std::exit(1);
			}
		}
	}
	std::cout << "\033[32mContact data added successfully!\033[0m" << std::endl;
	return (true);
}


/**
 * @brief Get the Contact object
 * 
 * @param index index of the contact
 */
void	Contact::GetContact(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->_data[i].length() > 10)
			std::cout << this->_data[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_data[i];
	}
	std::cout << "|" << std::endl;
}

/**
 * @brief Check if the contact is empty
 * 
 * @return true if the contact is empty
 */

bool	Contact::IsEmpty() const
{
	if (this->_data[FirstName].length() == 0)
		return (true);
	return (false);
}
