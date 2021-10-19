/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 05:52:46 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/18 15:42:26 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define CLASS_NAME "DiamondTrap "

static void	create_msg(std::string &name)
{
	std::cout << CLASS_NAME << name << " spawned." << std::endl;
}

static void	destroy_msg(std::string &name)
{
	std::cout << CLASS_NAME << name << " destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), Name(name)
{
	this->Hitpoints = FT_MAX_HP;
	this->Energy_points = ST_ENERGY_PTS;
	this->Attack_damage = FT_ATTACK_DMG;
	this->_maxHP = this->Hitpoints;
	create_msg(this->Name);
}

DiamondTrap::~DiamondTrap(void)
{
	destroy_msg(this->Name);
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
{
	std::cout << CLASS_NAME << this->Name << " is equal to " << src.Name << std::endl;
	this->Name = src.Name;
	this->Hitpoints = src.Hitpoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	this->_maxHP = src._maxHP;
	return (*this);
}

void		DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->Name << " and I am " << this->ClapTrap::Name << std::endl;
}