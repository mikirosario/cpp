/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:53 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 13:29:43 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

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
		virtual void		makeSound(void) const;
		std::string const	&getType(void) const;	
		virtual void		giveIdea(std::string const &src);
		virtual void		getIdea(void) const;	
};

#endif