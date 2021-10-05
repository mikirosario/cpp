/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:37:05 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:36:01 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HP
# define HUMANA_HP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon		&_weapon;
	std::string	_name;
	
public:
	HumanA(const char *name, Weapon &weapon_ref);
	void	attack();
};

#endif
