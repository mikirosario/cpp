/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:18:37 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 12:15:06 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat			&operator=(Cat const &src);
		void		makeSound(void) const;
		void		giveIdea(std::string const &src);
		void		getIdea(void) const;
		Brain const	&getBrain(void) const;
		void		copyBrain(Brain const &src);
};

#endif
