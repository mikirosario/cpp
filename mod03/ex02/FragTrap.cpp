/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:25:46 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 06:42:30 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define CLASS_NAME "FragTrap "

static void	create_msg(std::string const &name)
{
	std::cout << CLASS_NAME << name << " spawned." << std::endl;
}

static void	destroy_msg(std::string const &name)
{
	std::cout << CLASS_NAME << name << " destroyed." << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->Hitpoints = FT_MAX_HP;
	this->Energy_points = FT_ENERGY_PTS;
	this->Attack_damage = FT_ATTACK_DMG;
	this->_maxHP = FT_MAX_HP;
	create_msg(name);
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	create_msg(this->Name);
}

FragTrap::~FragTrap(void)
{
	destroy_msg(this->Name);
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	std::cout << CLASS_NAME << this->Name << " is equal to " << src.Name << std::endl;
	this->Name = src.Name;
	this->Hitpoints = src.Hitpoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	this->_maxHP = src._maxHP;
	return (*this);
}

void		FragTrap::attack(std::string const &target)
{
	std::cout << CLASS_NAME << this->Name << " attacks " << target << ", causing "
	<< this->Attack_damage << " points of damage!" << std::endl;
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << CLASS_NAME << this->Name << " shouts, 'Give me a high five!'" << std::endl;	
}
