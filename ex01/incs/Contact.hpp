/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:04:51 by mpietrza          #+#    #+#             */
/*   Updated: 2024/12/12 14:45:08 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
	private:
		static std::string	_NameOfField[5];
		std::string			_data[11];

		enum Field
		{
			FirstName,
			LastName,
			Nickname,
			PhoneNumber,
			DarkestSecret,
		};
	public:
		Contact(void);
		~Contact(void);

		bool	SetContact();
		void	GetContact(int index) const;
		bool	IsEmpty() const;
};

#endif
