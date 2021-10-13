/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:30:22 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 18:17:43 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#define CT_MAX_HP 10
#define CT_ENERGY_PTS 10
#define CT_ATTACK_DMG 0

class ClapTrap
{
	protected:
		std::string		Name;
		unsigned int	Hitpoints;
		unsigned int	Energy_points;
		unsigned int	Attack_damage;
		unsigned int	_maxHP;
	public:
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &src);
		virtual ~ClapTrap(void);
		ClapTrap		&operator=(ClapTrap const &src);
		virtual void	attack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif