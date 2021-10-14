/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:05:42 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 22:37:28 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : no_idea("This brain is empty"), ideas_held(0), index(0)
{
	std::cout << "Created a brain" << std::endl;
}

Brain::Brain(Brain const &src) : no_idea("This brain is empty"), ideas_held(0), index(0)
{
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Destroyed a brain" << std::endl;
}

Brain	&Brain::operator=(Brain const &src)
{
	for (int i = 0; i < BRAIN_H_IDEAS; i++)
	{
		this->ideas[i] = src.ideas[i];	
	}
	this->ideas_held = src.ideas_held;
	this->index = src.index;
	std::cout << "Copied a brain" << std::endl;
	return (*this);
}

void			Brain::setIdea(std::string const &src)
{
	if (ideas_held < BRAIN_H_IDEAS)
		this->ideas[ideas_held++] = src;
	else
		std::cout << "Brain too full for new ideas." << std::endl;
}

std::string const 	&Brain::getIdea(void)
{
	if (this->ideas_held == 0)
		return (this->no_idea);
	else
	{
		size_t	i = this->index;
		this->index = (this->index + 1) % this->ideas_held; //modular arithmetic to cycle ideas
		return (this->ideas[i]);
	}
}
