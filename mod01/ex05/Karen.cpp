/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:59 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 16:29:26 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() 
{
	_pair.first[0] = "DEBUG";
	_pair.first[1] = "INFO";
	_pair.first[2] = "WARNING";
	_pair.first[3] = "ERROR";
	_pair.second[0] = &Karen::debug;
	_pair.second[1] = &Karen::info;
	_pair.second[2] = &Karen::warning;
	_pair.second[3] = &Karen::error;
	_pair.second[4] = &Karen::level_does_not_exist;
}

void	Karen::level_does_not_exist(void)
{
	std::cerr << "Level does not exist. Karen spontaneously combusts." << std::endl;
}

void	Karen::debug(void)
{
	std::cerr << "I love to get extra bacon for my"
	<< " 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
	<< std::endl;
}

void	Karen::info(void)
{
	std::cerr << "I cannot believe adding extra bacon cost more money."
	<< " You don't put enough! If you did I would not have to ask for it!"
	<< std::endl;
}

void	Karen::warning(void)
{
	std::cerr << "I think I deserve to have some extra bacon for free"
	<< " I've been coming here for years and you just started working here last month."
	<< std::endl;
}

void	Karen::error(void)
{
	std::cerr << "This is unacceptable, I want to speak to the manager now."
	<< std::endl;
}

/*
** I made this way more arcane than I needed to, but I just really wanted to use
** a pair. xD
*/

void	Karen::complain(std::string level)
{
	int i;
	int ret;

	for (i = 0; i < 4 && (this->_pair.first[i].compare(level)); i++)
	{
	}
	(this->*_pair.second[i])();
}
