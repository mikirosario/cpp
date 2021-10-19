/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:53:59 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 04:30:08 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _Name("The Nameless One"), _inventory()
{
}

Character::Character(std::string const &src) : _Name(src), _inventory()
{
}

Character::Character(Character const &src) : _Name(src._Name), _inventory() //clone character
{
	*this = src;
}

Character::~Character()
{
}

Character			&Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_Name = src._Name;
		for (size_t i = 0; i < MAX_MATERIA; i++)
			this->_inventory[i] = src._inventory[i];
	}
	return (*this);
}

/*
** A bit of pointer voodoo to get the assignation to behave properly. xD
**
** Yes, that is a dereferenced pointer cast on the address of a reference.
**
** There is probably a prettier way to do this. xD
*/

ICharacter	&Character::operator=(ICharacter &src)
{
	return ((*this = *(Character *)&src));
}

std::string const	&Character::getName(void) const
{
	return (this->_Name);
}

void				Character::equip(AMateria *m)
{
	size_t	i;

	if (m == NULL)
		return ;
	for (i = 0; _inventory[i]; i++)
		if (i == MAX_MATERIA)
			return ;
	_inventory[i] = m;
}

void				Character::unequip(int idx)
{
	_inventory[idx] = NULL;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < MAX_MATERIA && _inventory[idx])
		_inventory[idx]->use(target);
}
