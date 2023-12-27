/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:46:27 by mburgler          #+#    #+#             */
/*   Updated: 2023/12/02 00:33:17 by mburgler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c++ -std=c++98 -Wall -Wextra -Werror -MMD -MP -pedantic

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		std::string args;
		for(int i = 1; i < argc; ++i) {
			for(int j = 0; argv[i][j] != '\0'; ++j) {
				args += std::toupper(argv[i][j]);
			}
		}
		std::cout << args << std::endl;
	}
	return (0);
}

	// std::string args;
	// while (++i < argc)
	// 	args += argv[i];
	// 			//std::cout << (char)toupper(argv[i][j]);
