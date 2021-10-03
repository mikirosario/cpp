/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:05:46 by miki              #+#    #+#             */
/*   Updated: 2021/10/03 15:49:22 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string ft_str_toupper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			std::string str(argv[i]);
			std::cout << ft_str_toupper(str);
		}
		std::cout << std::endl;
	}
	return (0);
}
