/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:30 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/11 17:16:08 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	bool		is_exit = false;
	std::string	command;

	PhoneBook.PrintManual();
	while (is_exit == false && std::getline(std::cin, command))
	{
		if (std::cin.eof() == true)
			{
				std::cout << "Ctrl - D pressed - exiting the phone book." << std::endl;
				std::exit(0);
			}
		else if (command.compare("ADD") == 0)
			PhoneBook.SetData();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.GetData();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Exiting the phone book."<< std::endl;
			is_exit = true;
			break ;
		}
		command.clear();
		PhoneBook.ShowInstruction();
	}
	return (0);
}

