/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:59:01 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:35:36 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const char *name) : _name("HumanB"), _weapon(NULL)
{
	if (name)
		this->_name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << (this->_weapon ? this->_weapon->getType() : "bare fist")
	<< std::endl;
}
