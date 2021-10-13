/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:19:50 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 17:33:57 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CLASS "Cat"
#define SOUND " goes meow."
#define CREATE_MSG "Created a "
#define DESTROY_MSG "Destroyed a "
#define COPY_MSG "Copied a "

Cat::Cat(void) : Animal((std::string)CLASS)
{
	std::cout << CREATE_MSG << this->type << std::endl;
}

Cat::Cat(Cat const &src)
{
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << DESTROY_MSG << this->type << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	this->type = src.type;
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}
