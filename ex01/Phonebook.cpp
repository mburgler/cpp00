/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:28 by mburgler          #+#    #+#             */
/*   Updated: 2023/12/20 16:33:36 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	contacts_count = 0;
}

Phonebook::~Phonebook(void)
{
}

void	Phonebook::run(void)
{
	e_choice	choice;
	std::string	input;

	std::cout << BOLD GREEN "\n~~~~~~~~~ welcome <3 ~~~~~~~~~\n" RESET << std::endl;
	while (1)
	{
		choice = get_choice(input);
		if (choice == EXIT) {
			std::cout << BOLD GREEN "\n~~~~~~~~~ goodbye <3 ~~~~~~~~~\n" RESET<< std::endl;
			break ;
		}
		else if (choice == ADD)
			add_contact();
		else if (choice == SEARCH)
			search_contact();
		else if (choice == INVALID)
			std::cout << RED "\"" U_SCORE << input << RESET RED "\" not recognised" RESET << std::endl;
		else if (choice == EMPTY)
			std::cout << RED "you just pressed enter without a valid command." RESET << std::endl;
		//DEBUG
		else if(choice == DEBUG)
		{
			for(int i = 0; i < 8; ++i)
			contacts[i].debug_print_contact(i);
		}
	}
}

Phonebook::e_choice	Phonebook::get_choice(std::string& input)
{
	std::string	choice;

	std::cout << GREEN "please enter a command (ADD, SEARCH, EXIT): " RESET;
	std::getline(std::cin, input);
	if(std::cin.eof())
	{
		std::cout << std::endl;
		std::cout << RED "EOF encountered ... goodbye :)" RESET << std::endl;
		exit(0);
	}
	choice = to_upper(input);
	if (choice == "")
		return (EMPTY);
	else
	if (choice == "ADD")
		return (ADD);
	else if (choice == "SEARCH")
		return (SEARCH);
	else if (choice == "EXIT")
		return (EXIT);
	//DEBUG
	else if (choice == "SECRET_DEBUG")
		return (DEBUG);
	else
		return (INVALID);
}

void	Phonebook::add_contact(void)
{
	std::string data[5];

	if (contacts_count == 8)
		contacts_count = 0;
	for(int i = 0; i < 5; ++i)
		get_contact_data(static_cast<Contact::e_datatype>(i), data[i]);
	for (int i = 0; i < 5; ++i)
		contacts[contacts_count].set_contact(data[i], static_cast<Contact::e_datatype>(i));
	contacts_count++;
}

//contacts[0].give_description(static_cast<Contact::e_datatype>(i))

bool	Phonebook::get_contact_data(Contact::e_datatype type, std::string& data)
{
	bool is_nmb;

	while(1){
		is_nmb = true;
		std::cout << MAGENTA "please enter " << contacts[0].give_description(type) << ": " << RESET;
		std::getline(std::cin, data);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << RED "EOF encountered ... goodbye :)" RESET << std::endl;
			exit(0);
		}
		if (data.empty())
		{
			std::cout << RED "contact can’t have empty fields." RESET << std::endl;
			continue ;
		}
		else if(data.find_first_of("\t\n\v\f\röäü") != std::string::npos)
		{
			std::cout << RED "invalid input." RESET << std::endl;
			continue ;
		}
		else if (type == Contact::PHONE_NUMBER)
		{
			for (int i = 0; data[i] != '\0'; ++i)
			{
				if (std::isdigit(data[i]) == false)
				{
					is_nmb = false;
					std::cout << RED "phone number can only contain numbers." RESET << std::endl;
					break ;
				}
			}
			if (is_nmb == true)
				return (true);
		}
		else
			return (true);
	}
	return (true);
}

void	Phonebook::search_contact(void)
{
	std::string input;
	int index = 0;

	if (contacts_count == 0)
	{
		std::cout << RED "no contacts to search for." RESET << std::endl;
		return ;
	}
	print_contact_table();
	while(1)
	{
		std::cout << MAGENTA "please enter an index: " RESET;
		std::getline(std::cin, input);
		if(std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << RED "EOF encountered ... goodbye :)" RESET << std::endl;
			exit(0);
		}
		std::stringstream ss(input);
		if (!(ss >> index) || !ss.eof())
		{
			std::cout << RED "invalid input." RESET << std::endl;
			continue ;
		}
		else if (index < 0 || index >= contacts_count)
		{
			std::cout << RED "index out of range." RESET << std::endl;
			continue ;
		}
		else
		{
			std::cout << std::endl;
			for(int i = 0; i < 5; ++i)
			{
				std::cout << CYAN << contacts[0].give_description(static_cast<Contact::e_datatype>(i)) << ": " RESET;
				std::cout << contacts[index].give_contact(static_cast<Contact::e_datatype>(i)) << std::endl;
			}
			std::cout << std::endl;
			break ;
		}
	}
}

//index, first name, last name and nickname

void	Phonebook::print_contact_table()
{
	std::cout << std::endl;
	std::cout << std::setw(10) << std::right << CYAN << "index";
	for (int i = 0; i < 3; ++i)
	{
	std::cout << "|";
		std::cout << std::setw(10) << std::right << contacts[0].give_description(static_cast<Contact::e_datatype>(i));
	}
	std::cout << RESET << std::endl;
	for(int i = 0; i < 43; ++i)
		std::cout << CYAN "-";
	std::cout << RESET << std::endl;
	for (int i = 0; i < contacts_count; ++i)
	{
		std::cout << std::setw(10) << std::right << i;
		for (int j = 0; j < 3; ++j)
		{
			std::cout << "|";
			std::cout << std::setw(10) << std::right << shorten(contacts[i].give_contact(static_cast<Contact::e_datatype>(j)));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::string Phonebook::shorten(std::string str)
{
	std::string	short_str;

	if (str.length() > 10)
	{
		short_str = str.substr(0, 9);
		short_str += ".";
	}
	else
		short_str = str;
	return (short_str);
}

std::string	Phonebook::to_upper(std::string str){
	std::string	upper_str;

	for (int i = 0; str[i] != '\0'; ++i)
		upper_str += std::toupper(str[i]);
	return (upper_str);
}
