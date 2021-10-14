/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:32:35 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 12:14:46 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	protected:
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);
		Dog			&operator=(Dog const &src);
		void		makeSound(void) const;
		void		giveIdea(std::string const &src);
		void		getIdea(void) const;
		Brain const	&getBrain(void) const;
		void		copyBrain(Brain const &src);
};

#endif
