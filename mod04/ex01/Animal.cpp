/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:32:26 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 14:34:35 by miki             ###   ########.fr       */
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

/*
** A bit of dynamic typecast is used here so my main doesn't need a bajillion
** typecasts. If ltype is a dog or cat and rtype is a dog or cat, we typecast
** the pointer the current instance (this) to the source type and use the
** copyBrain method to copy the brain.
**
** If ltype is a dog or cat but rtype is not, or if rtype is a dog or cat but
** ltype is not, we reject the copy and just return a reference to the current
** instance.
** 
** Personally I think the type variable should always correspond to the class,
** so it shouldn't be copied. Type should only be defined on initialization, and
** so should be const, but it isn't here to comply with the subject.
*/

Animal	&Animal::operator=(Animal const &src)
{
	Dog const *iamdog = dynamic_cast<Dog*>(this);
	Cat const *iamcat = dynamic_cast<Cat*>(this);
	Dog const *srcisdog = dynamic_cast<const Dog*>(&src);
	Cat const *srciscat = dynamic_cast<const Cat*>(&src);	;
	if (iamdog != NULL || iamcat != NULL)
	{
		if (srcisdog != NULL)
		{
			std::cout << "PERRO" << std::endl;
			((Dog *)this)->copyBrain(srcisdog->getBrain());
		}
		else if (srciscat != NULL)
		{
			std::cout << "GATO" << std::endl;
			((Cat *)this)->copyBrain(srciscat->getBrain());
		}
		else
		{
			std::cout << "Cannot copy brainless animal to brainy animal" << std::endl;
			return (*this);
		}
	}
	else if (srciscat != NULL || srcisdog != NULL)
	{
		std::cout << "Cannot copy brainy animal to brainless animal" << std::endl;
		return (*this);
	}
	//this->type = src.type;

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
	Dog const *dog = dynamic_cast<Dog const*>(this);
	Cat const *cat = dynamic_cast<Cat const*>(this);

	if (dog != NULL)
		dog->makeSound();
	else if (cat != NULL)
		cat->makeSound();
	else
	{
		std::cout << "The ";
		if (!this->has_type)
			std::cout << CLASS << SOUND << std::endl;
		else
			std::cout << TYPEFUL_CLASS << SOUND << std::endl;
	}
}

std::string const	&Animal::getType(void) const
{
	return (this->type);
}

void	Animal::giveIdea(std::string const &src)
{
	Dog *dog = dynamic_cast<Dog*>(this);
	Cat *cat = dynamic_cast<Cat*>(this);

	if (dog != NULL)
		dog->giveIdea(src);
	else if (cat != NULL)
		cat->giveIdea(src);
}

void	Animal::getIdea(void) const
{
	Dog const *dog = dynamic_cast<Dog const*>(this);
	Cat const *cat = dynamic_cast<Cat const*>(this);

	if (dog != NULL)
		dog->getIdea();
	else if (cat != NULL)
		cat->getIdea();
}
