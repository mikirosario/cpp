/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:27:20 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 16:34:08 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(AMateria const &src) : _type(src._type)
{
}

AMateria::~AMateria(void)
{
}

AMateria	&AMateria::operator=(AMateria const &src)
{
	this->_type = src._type;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}
