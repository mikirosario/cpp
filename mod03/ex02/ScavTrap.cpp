/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:59:22 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 03:20:36 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define CLASS_NAME "ScavTrap "

static void	create_msg(std::string const &name)
{
	std::cout << CLASS_NAME << name << " spawned." << std::endl;
}

static void	destroy_msg(std::string const &name)
{
	std::cout << CLASS_NAME << name << " destroyed." << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	create_msg(name);
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	create_msg(this->Name);
}

ScavTrap::~ScavTrap(void)
{
	destroy_msg(this->Name);
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	std::cout << CLASS_NAME << this->Name << " is equal to " << src.Name << std::endl;
	this->Name = src.Name;
	this->Hitpoints = src.Hitpoints;
	this->Energy_points = src.Energy_points;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void		ScavTrap::attack(std::string const &target)
{
	std::cout << CLASS_NAME << this->Name << " attacks " << target << ", causing "
	<< this->Attack_damage << " points of damage!" << std::endl;
}

void		ScavTrap::guardGate(void)
{
	std::cout << CLASS_NAME << this->Name << " entered Gate Keeper Mode." << std::endl;
}
