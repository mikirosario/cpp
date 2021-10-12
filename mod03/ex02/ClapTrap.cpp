/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:54:42 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 06:40:19 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#define CLASS_NAME "ClapTrap "

static void	create_msg(std::string &name)
{
	std::cout << CLASS_NAME << name << " spawned." << std::endl;
}

static void	destroy_msg(std::string &name)
{
	std::cout << CLASS_NAME << name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : Name(name), Hitpoints(CT_MAX_HP),
Energy_points(CT_ENERGY_PTS), Attack_damage(CT_ATTACK_DMG), _maxHP(CT_MAX_HP)
{
	create_msg(this->Name);
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	create_msg(this->Name);
}

ClapTrap::~ClapTrap(void)
{
	destroy_msg(this->Name);
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << CLASS_NAME << this->Name << " is equal to " << src.Name << std::endl;
	this->Name = src.Name;
	this->Hitpoints = src.Hitpoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	this->_maxHP = src._maxHP;
	return (*this);
}

void		ClapTrap::attack(std::string const &target)
{
	std::cout << CLASS_NAME << this->Name << " attacks " << target << ", causing "
	<< this->Attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	points_to_die = (this->Hitpoints);
	bool			lost_all_hitpoints = (amount >= this->Hitpoints);

	if (lost_all_hitpoints)
		this->Hitpoints = 0;
	else
		this->Hitpoints -= amount;
	std::cout << CLASS_NAME << this->Name << " takes "
	<< (lost_all_hitpoints ? points_to_die : amount)
	<< " points of damage, and is left with " << this->Hitpoints
	<< " hitpoints." << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	points_to_heal_fully = (this->_maxHP - this->Hitpoints);
	bool			healed_fully = (amount >= points_to_heal_fully);

	if (healed_fully)
		this->Hitpoints = this->_maxHP;
	else
		this->Hitpoints += amount;
	std::cout << CLASS_NAME << this->Name << " heals "
	<< (healed_fully ? points_to_heal_fully : amount)
	<< " points of damage, and is left with " << this->Hitpoints
	<< " hitpoints." << std::endl;
}
