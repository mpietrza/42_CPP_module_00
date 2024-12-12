/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:30 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/12 16:51:07 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PhoneBook.hpp"
#include "../incs/Contact.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	bool		is_exit = false;
	bool		is_empty_command = false;
	std::string	command;

	PhoneBook.PrintInstruction();
	while (is_exit == false && std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			PhoneBook.SetData();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.GetData();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "\033[1;34mExiting the phone book.\033[0m" << std::endl;
			is_exit = true;
			break ;
		}
		else if (command.empty() == true)
		{
			command.clear();
			is_empty_command = true;
		}
		else
			std::cout << "\033[1;31mError: unknown command!\033[0m" << std::endl;
		command.clear();
		if (is_empty_command == false)
			PhoneBook.PrintInstruction();
		else
			is_empty_command = false;
	}
	if (std::cin.eof() == true)
		std::cout << "\033[1;34mCtrl - D pressed - exiting the phone book.\033[0m" << std::endl;
	return (0);
}

