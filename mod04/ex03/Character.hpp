/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:43:15 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 02:01:57 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#define	MAX_MATERIA 4

class Character : public ICharacter
{
	protected:
		std::string 		_Name;
		AMateria			*_inventory[MAX_MATERIA];
	public:
		Character(void);
		Character(std::string const &src);
		Character(Character const &src);
		~Character();
		Character	&operator=(Character const &src);
	//Interface (Pure Virtual)
		std::string const &getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
