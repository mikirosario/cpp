/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:32:26 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 12:17:42 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define CLASS "Animal"
#define TYPEFUL_CLASS CLASS << " of type " << this->type
#define SOUND " goes brrp."
#define CREATE_MSG "Created an "
#define DESTROY_MSG "Destroyed an "
#define COPY_MSG "Copied an "


static bool	checkEmptyString(std::string str)
{
	size_t strlen = str.length();

	for (size_t i = 0; i < strlen; i++)
		if (str[i])
			return (false);
	return (true);
}

Animal::Animal(void) : type(""), has_type(false)
{
	std::cout << CREATE_MSG << CLASS << std::endl;
}

Animal::Animal(std::string const &src) : type(src)
{
	if (checkEmptyString(src) || !src.compare(CLASS))
	{
		std::cout << CREATE_MSG << CLASS << std::endl;
		this->has_type = false;
	}
	else
	{
		std::cout << CREATE_MSG << TYPEFUL_CLASS << std::endl;
		this->has_type = true;
	}
}

Animal::Animal(Animal const &src)
{
	*this = src;
}

Animal::~Animal(void)
{
	if (checkEmptyString(this->type) || !this->type.compare(CLASS))
		std::cout << DESTROY_MSG << CLASS << std::endl;
	else
		std::cout << DESTROY_MSG << TYPEFUL_CLASS << std::endl;
}

Animal	&Animal::operator=(Animal const &src)
{
	Dog const *dog = dynamic_cast<const Dog*>(&src);
	Cat const *cat = dynamic_cast<const Cat*>(&src);
	
	if (dog != NULL)
		((Dog *)this)->copyBrain(dog->getBrain());
	else if (cat != NULL)
		((Cat *)this)->copyBrain(cat->getBrain());
	this->type = src.type;

	std::cout << COPY_MSG;
	if (checkEmptyString(this->type) || !this->type.compare(CLASS))
	{
		std::cout << CLASS << std::endl;
		this->has_type = false;
	}
	else
	{
		std::cout << TYPEFUL_CLASS << std::endl;
		this->has_type = true;
	}
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "The ";
	if (!this->has_type)
		std::cout << CLASS << SOUND << std::endl;
	else
		std::cout << TYPEFUL_CLASS << SOUND << std::endl;
}

std::string const	&Animal::getType(void) const
{
	return (this->type);
}


