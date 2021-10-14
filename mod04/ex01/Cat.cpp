/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:19:50 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 12:15:16 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CLASS "Cat"
#define SOUND " goes meow."
#define CREATE_MSG "Created a "
#define DESTROY_MSG "Destroyed a "
#define COPY_MSG "Copied a "

Cat::Cat(void) : Animal((std::string)CLASS), brain(new Brain)
{
	std::cout << CREATE_MSG << this->type << std::endl;
}

Cat::Cat(Cat const &src) : Animal((std::string)CLASS), brain(new Brain)
{
	*this = src;
	std::cout << COPY_MSG << this->type << std::endl;
}

Cat::~Cat(void)
{
	if (this->brain != NULL)
		delete (this->brain);
	std::cout << DESTROY_MSG << this->type << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	this->type = src.type;
	if (this->brain == NULL)
 		this->brain = new Brain();
 	if (this->brain != NULL)
 		*this->brain = *src.brain;
	std::cout << COPY_MSG << this->type << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "The " << CLASS << SOUND << std::endl;
}

void	Cat::giveIdea(std::string const &src)
{
	if (this->brain)
		this->brain->setIdea(src);
}

void	Cat::getIdea(void) const
{
	if (this->brain)
		std::cout << this->brain->getIdea() << std::endl;
}

Brain const	&Cat::getBrain(void) const
{
	return (*this->brain);
}

void		Cat::copyBrain(Brain const &src)
{	
	if (this->brain == NULL)
		this->brain = new Brain();
	if (this->brain != NULL)
		*this->brain = src;
}
