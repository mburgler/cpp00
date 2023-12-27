/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:06:46 by mburgler          #+#    #+#             */
/*   Updated: 2023/12/20 15:19:49 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::set_contact(std::string data, e_datatype type)
{
	if (type == FIRST_NAME)
		first_name = data;
	else if (type == LAST_NAME)
		last_name = data;
	else if (type == NICKNAME)
		nickname = data;
	else if (type == PHONE_NUMBER)
		phone_number = data;
	else if (type == DARKEST_SECRET)
		darkest_secret = data;
}

std::string	Contact::give_contact(e_datatype type)
{
	if (type == FIRST_NAME)
		return(first_name);
	else if (type == LAST_NAME)
		return(last_name);
	else if (type == NICKNAME)
		return(nickname);
	else if (type == PHONE_NUMBER)
		return(phone_number);
	else if (type == DARKEST_SECRET)
		return(darkest_secret);
	return ("");
}

std::string	Contact::give_description(e_datatype type)
{
	if (type == FIRST_NAME)
		return("first name");
	else if (type == LAST_NAME)
		return("last name");
	else if (type == NICKNAME)
		return("nickname");
	else if (type == PHONE_NUMBER)
		return("phone number");
	else if (type == DARKEST_SECRET)
		return("darkest secret");
	return ("");
}

void 	Contact::debug_print_contact(int index)
{
	std::cout << BOLD CYAN "### debug_print_contact no " << index << " ###" RESET << std::endl;
	std::cout << "first_name: " << first_name << std::endl;
	std::cout << "last_name: " << last_name << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone_number: " << phone_number << std::endl;
	std::cout << "darkest_secret: " << darkest_secret << std::endl;
}