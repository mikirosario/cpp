/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:54:42 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 00:19:11 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	create_msg(std::string &name)
{
	std::cout << name << " spawned." << std::endl;
}

static void	destroy_msg(std::string &name)
{
	std::cout << name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : Name(name), Hitpoints(10),
Energy_points(10), Attack_damage(0)
{
	create_msg(this->Name);
}

ClapTrap::ClapTrap(ClapTrap const &clap_trap)
{
	*this = clap_trap;
	create_msg(this->Name);
}

ClapTrap::~ClapTrap(void)
{
	destroy_msg(this->Name);
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &clap_trap)
{
	std::cout << this->Name << " is equal to " << clap_trap.Name << std::endl;
	this->Name = clap_trap.Name;
	this->Hitpoints = clap_trap.Hitpoints;
	this->Energy_points = clap_trap.Energy_points;
	this->Attack_damage = clap_trap.Attack_damage;
	return (*this);
}

void		ClapTrap::attack(std::string const &target)
{
	std::cout << this->Name << " attacks " << target << ", causing "
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
	std::cout << this->Name << " takes "
	<< (lost_all_hitpoints ? points_to_die : amount)
	<< " points of damage, and is left with " << this->Hitpoints
	<< " hitpoints." << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	points_to_heal_fully = (10 - this->Hitpoints);
	bool			healed_fully = (amount >= points_to_heal_fully);

	if (healed_fully)
		this->Hitpoints = 10;
	else
		this->Hitpoints += amount;
	std::cout << this->Name << " heals "
	<< (healed_fully ? points_to_heal_fully : amount)
	<< " points of damage, and is left with " << this->Hitpoints
	<< " hitpoints." << std::endl;
}

std::string	&ClapTrap::getName(void)
{
	return (this->Name);
}