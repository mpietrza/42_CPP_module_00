/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:07:05 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/11 17:04:21 by mpietrza         ###   ########.fr       */
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
		Contact	_contacts[8];
		int		_index;
		bool	_is_full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	SetData(void);
		void	GetData(void) const;
		void	ShowInstruction(void);
};

#endif
