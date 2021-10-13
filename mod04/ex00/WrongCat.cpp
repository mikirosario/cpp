/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:39:49 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 16:40:01 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define CLASS "WrongCat"
#define SOUND " goes meow."
#define CREATE_MSG "Created a "
#define DESTROY_MSG "Destroyed a "
#define COPY_MSG "Copied a "

WrongCat::WrongCat(void) : WrongAnimal((std::string)CLASS)
{
	std::cout << CREATE_MSG << this->type << std::endl;
}

WrongCat::WrongCat(WrongCat &src)
{
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << DESTROY_MSG << this->type << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat &src)
{
	this->type = src.type;
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}
