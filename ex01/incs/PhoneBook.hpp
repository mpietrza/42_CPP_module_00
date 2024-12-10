/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:07:05 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/10 16:12:32 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_Contacts[8];
		int		_Index;
		bool	_Full;

	public:
		PhoneBook(void)
		~PhoneBook(void);

		void	SetInformation(void);
		void	GetInformation(void) const;
		void	show_instruction(void);
};

#endif
