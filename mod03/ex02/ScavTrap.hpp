/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:56:20 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 06:25:25 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"
#define ST_MAX_HP 100
#define ST_ENERGY_PTS 50
#define ST_ATTACK_DMG 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);
		ScavTrap	&operator=(ScavTrap const &src);
		void		attack(std::string const &target);
		void		guardGate(void);
};

#endif