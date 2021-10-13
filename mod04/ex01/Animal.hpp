/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:53 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 23:15:17 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include "Brain.hpp"

class Animal
{
	private:
		Brain	*brain;
	protected:
		std::string type;
		bool		has_name;
		void		setBrain(void);
		void		deleteBrain(void);
		void		copyBrain(Brain const &src);
		Brain const	&getBrain(void) const;
	public:
		Animal(void);
		Animal (std::string const &src);
		Animal (Animal const &src);
		virtual ~Animal(void);
		virtual Animal		&operator=(Animal const &src);
		virtual void		makeSound(void) const;
		std::string const	&getType(void) const;
		void				giveIdea(std::string const &src);
		void				getIdea(void) const;
		
};

#endif