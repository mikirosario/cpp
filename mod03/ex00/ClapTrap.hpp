/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:30:22 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/11 23:40:37 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:
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
		std::string	&getName(void);
};

#endif