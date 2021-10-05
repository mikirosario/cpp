/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:26:18 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:36:04 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const char *type) : _type(type)
{
}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}

void				Weapon::setType(const char *type)
{
	this->_type = type;
}
