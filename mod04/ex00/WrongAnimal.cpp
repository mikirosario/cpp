/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:37:03 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 16:45:01 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define CLASS "WrongAnimal"
#define TYPEFUL_CLASS CLASS << " of type " << this->type
#define SOUND " goes brrp."
#define CREATE_MSG "Created a "
#define DESTROY_MSG "Destroyed a "
#define COPY_MSG "Copied a "

static bool	checkEmptyString(std::string str)
{
	size_t strlen = str.length();

	for (size_t i = 0; i < strlen; i++)
		if (str[i])
			return (false);
	return (true);
}

WrongAnimal::WrongAnimal(void) : type(""), has_name(false)
{
	std::cout << CREATE_MSG << CLASS << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &src) : type(src)
{
	if (checkEmptyString(src) || !src.compare(CLASS))
	{
		std::cout << CREATE_MSG << CLASS << std::endl;
		this->has_name = false;
	}
	else
	{
		std::cout << CREATE_MSG << TYPEFUL_CLASS << std::endl;
		this->has_name = true;
	}
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	if (checkEmptyString(this->type) || !this->type.compare(CLASS))
		std::cout << DESTROY_MSG << CLASS << std::endl;
	else
		std::cout << DESTROY_MSG << TYPEFUL_CLASS << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	this->type = src.type;
	std::cout << COPY_MSG;
	if (checkEmptyString(this->type) || !this->type.compare(CLASS))
	{
		std::cout << CLASS << std::endl;
		this->has_name = false;
	}
	else
	{
		std::cout << TYPEFUL_CLASS << std::endl;
		this->has_name = true;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "The ";
	if (!this->has_name)
		std::cout << CLASS << SOUND << std::endl;
	else
		std::cout << TYPEFUL_CLASS << SOUND << std::endl;
}

std::string const	&WrongAnimal::getType(void) const
{
	return (this->type);
}
