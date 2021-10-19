/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:29:08 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 04:30:25 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

//#include "AMateria.hpp" cyclical reference leads compiler to believe there
//there are two use methods in AMateria??
#include <iostream>

class AMateria;

class ICharacter
{
	public:
		virtual ICharacter	&operator=(ICharacter &src) = 0; //Added this pure virtual to divert assignments to child class
		virtual ~ICharacter() {};
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif
