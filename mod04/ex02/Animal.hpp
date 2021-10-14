/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:53 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 16:51:59 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

/*
** Type should really be const, so it always coincides with the class - that
** would save a LOT of trouble, but... subject says it isn't, so... :p
*/

class Animal
{
	protected:
		std::string type;
		bool		has_type;
	public:
		Animal(void);
		Animal (std::string const &src);
		Animal (Animal const &src);
		virtual ~Animal(void);
		Animal				&operator=(Animal const &src);
		virtual void		makeSound(void) const = 0;
		std::string const	&getType(void) const;	
		virtual void		giveIdea(std::string const &src);
		virtual void		getIdea(void) const;	
};

#endif