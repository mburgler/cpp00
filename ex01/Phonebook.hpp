/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:32 by mburgler          #+#    #+#             */
/*   Updated: 2023/12/21 12:10:08 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cctype>
# include "Contact.hpp"
# include "Colour.hpp"

class Phonebook{
	public:
		Phonebook(void);
		~Phonebook(void);

		void	run(void);
	private:
		enum e_choice {EMPTY, DEBUG, INVALID, ADD, SEARCH, EXIT};
		Contact	contacts[8];
		int		contacts_count;

		e_choice	get_choice(std::string& input);
		std::string	to_upper(std::string str);
		void	add_contact(void);
		void	search_contact(void);
		bool	get_contact_data(Contact::e_datatype type, std::string& data);
		void	print_contact_table();
		std::string	shorten(std::string str);
};

#endif
