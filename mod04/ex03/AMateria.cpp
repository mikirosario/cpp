/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:27:20 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 04:30:04 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Type Not Set!")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(AMateria const &src) : _type(src._type)
{
}

AMateria::~AMateria(void)
{
}

AMateria	&AMateria::operator=(AMateria const &src) //?? assignment between unlike types makes no sense
{
	(void)src;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void				AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "Debug AMateria.hpp" << std::endl;
}
