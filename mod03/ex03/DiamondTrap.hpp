/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 05:45:47 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 08:19:26 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
	private:
		std::string	Name;
	public:
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);
		DiamondTrap	&operator=(DiamondTrap const &src);
		void		attack(std::string const &target);
		void		whoAmI(void);
};

#endif