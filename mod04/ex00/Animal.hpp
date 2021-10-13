/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:26:53 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 17:28:00 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal
{
	protected:
		std::string type;
		bool		has_name;
	public:
		Animal(void);
		Animal (std::string const &src);
		Animal (Animal const &src);
		virtual ~Animal(void);
		Animal				&operator=(Animal const &src);
		virtual void		makeSound(void) const;
		std::string const	&getType(void) const;
};

#endif