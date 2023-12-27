/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:06:16 by mburgler          #+#    #+#             */
/*   Updated: 2023/12/20 15:21:39 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Colour.hpp"

class Contact{
	public:
		Contact(void);
		~Contact(void);

		enum e_datatype {FIRST_NAME, LAST_NAME, NICKNAME, PHONE_NUMBER, DARKEST_SECRET};
		void	set_contact(std::string data, e_datatype type);
		std::string	give_contact(e_datatype type);
		void	debug_print_contact(int index);
		static std::string give_description(e_datatype type);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
