/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:08 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 17:34:10 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define CLASS "Dog"
#define SOUND " goes woof."
#define CREATE_MSG "Created a "
#define DESTROY_MSG "Destroyed a "
#define COPY_MSG "Copied a "

Dog::Dog(void) : Animal((std::string)CLASS)
{
	std::cout << CREATE_MSG << this->type << std::endl;
}

Dog::Dog(Dog const &src)
{
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << DESTROY_MSG << this->type << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	this->type = src.type;
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}
