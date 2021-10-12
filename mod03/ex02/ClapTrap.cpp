/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:54:42 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 03:18:33 by mrosario         ###   ########.fr       */
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

ClapTrap::ClapTrap(std::string const &name) : Name(name), Hitpoints(MAX_HP),
Energy_points(ENERGY_PTS), Attack_damage(ATTACK_DMG)
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
	std::cout << CLASS_NAME << this->Name << " is equal to " << clap_trap.Name << std::endl;
	this->Name = clap_trap.Name;
	this->Hitpoints = clap_trap.Hitpoints;
	this->Energy_points = clap_trap.Energy_points;
	this->Attack_damage = clap_trap.Attack_damage;
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
	unsigned int	points_to_heal_fully = (MAX_HP - this->Hitpoints);
	bool			healed_fully = (amount >= points_to_heal_fully);

	if (healed_fully)
		this->Hitpoints = MAX_HP;
	else
		this->Hitpoints += amount;
	std::cout << CLASS_NAME << this->Name << " heals "
	<< (healed_fully ? points_to_heal_fully : amount)
	<< " points of damage, and is left with " << this->Hitpoints
	<< " hitpoints." << std::endl;
}
