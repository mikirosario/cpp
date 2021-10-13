/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:08 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 23:16:29 by mrosario         ###   ########.fr       */
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
	this->Animal::setBrain();
	std::cout << CREATE_MSG << this->type << std::endl;
}

Dog::Dog(Dog const &src) : Animal((std::string)CLASS)
{
	this->Animal::copyBrain(src.getBrain());
	std::cout << COPY_MSG << this->type << std::endl;
}

Dog::~Dog(void)
{
	this->deleteBrain();
	std::cout << DESTROY_MSG << this->type << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	this->type = src.type;
	this->Animal::copyBrain(src.getBrain());
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}
