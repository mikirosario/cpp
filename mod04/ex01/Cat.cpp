/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:19:50 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 23:16:37 by mrosario         ###   ########.fr       */
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
	this->Animal::setBrain();
	std::cout << CREATE_MSG << this->type << std::endl;
}

Cat::Cat(Cat const &src) : Animal((std::string)CLASS)
{
	this->Animal::copyBrain(src.getBrain());
	std::cout << COPY_MSG << this->type << std::endl;
}

Cat::~Cat(void)
{
	this->deleteBrain();
	std::cout << DESTROY_MSG << this->type << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	this->type = src.type;
	this->Animal::copyBrain(src.getBrain());
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}
