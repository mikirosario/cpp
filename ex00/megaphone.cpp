/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:05:46 by miki              #+#    #+#             */
/*   Updated: 2021/09/27 00:06:18 by miki             ###   ########.fr       */
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
		std::cout << "No argument" << std::endl;
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
