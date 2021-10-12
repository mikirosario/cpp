/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:21:32 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 06:48:04 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"
#define FT_MAX_HP 100
#define FT_ENERGY_PTS 100
#define FT_ATTACK_DMG 30

class FragTrap : virtual public ClapTrap
{
	protected:
		FragTrap(void);
	public:
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap	&operator=(FragTrap const &src);
		void		attack(std::string const &target);
		void		highFivesGuys(void);
};

#endif