/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:51:14 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:35:46 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HP
# define HUMANB_HP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*_weapon;
	std::string	_name;
	
public:
	HumanB(const char *name);
	void	setWeapon(Weapon &weapon);
	void	attack();
};

#endif
