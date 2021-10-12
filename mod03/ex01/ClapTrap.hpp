/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:30:22 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 03:13:41 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#define MAX_HP 100
#define ENERGY_PTS 50
#define ATTACK_DMG 20


class ClapTrap
{
	protected:
		std::string Name;
		unsigned int Hitpoints;
		unsigned int Energy_points;
		unsigned int Attack_damage;
	public:
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &clap_trap);
		~ClapTrap(void);
		ClapTrap	&operator=(ClapTrap const &clap_trap);
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif