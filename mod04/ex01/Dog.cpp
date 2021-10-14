/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:08 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 12:08:01 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define CLASS "Dog"
#define SOUND " goes woof."
#define CREATE_MSG "Created a "
#define DESTROY_MSG "Destroyed a "
#define COPY_MSG "Copied a "

Dog::Dog(void) : Animal((std::string)CLASS), brain(new Brain)
{
	std::cout << CREATE_MSG << this->type << std::endl;
}

Dog::Dog(Dog const &src) : Animal((std::string)CLASS), brain(new Brain)
{
	*this = src;
	std::cout << COPY_MSG << this->type << std::endl;
}

Dog::~Dog(void)
{
	if (this->brain != NULL)
		delete (this->brain);
	std::cout << DESTROY_MSG << this->type << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	this->type = src.type;
	if (this->brain == NULL)
 		this->brain = new Brain();
 	if (this->brain != NULL)
 		*this->brain = *src.brain;
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}

void	Dog::giveIdea(std::string const &src)
{
	if (this->brain)
		this->brain->setIdea(src);
}

void	Dog::getIdea(void) const
{
	if (this->brain)
		std::cout << this->brain->getIdea() << std::endl;
}

Brain const	&Dog::getBrain(void) const
{
	return (*this->brain);
}

void		Dog::copyBrain(Brain const &src)
{	
	if (this->brain == NULL)
		this->brain = new Brain();
	if (this->brain != NULL)
		*this->brain = src;
}
