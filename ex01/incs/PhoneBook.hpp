/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:07:05 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/12 16:42:14 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"
# include <limits>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		bool	_is_full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	SetData(void);
		void	GetData(void) const;
		void	ShowInstruction(void);
		void	PrintInstruction(void) const;
};

#endif
