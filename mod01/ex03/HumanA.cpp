/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:45:33 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:35:56 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const char *name, Weapon &weapon_ref) : _name("HumanA"), _weapon(weapon_ref)
{
	if (name)
		this->_name = name;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType()
	<< std::endl;
}
