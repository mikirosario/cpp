/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:21:25 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:36:06 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon(const char *type);
	const std::string	&getType();
	void				setType(const char *type);
};

#endif
