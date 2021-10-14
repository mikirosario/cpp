/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:24:35 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 16:53:56 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>

class AMateria
{
	protected:
		std::string	_type;
	//[...]
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		~AMateria(void);
		AMateria	&operator=(AMateria const &src);

	//[...]
		std::string const	&getType(void) const; //Returns the materia type
		virtual AMateria 	*clone(void) const = 0;
		//virtual void		use(ICharacter &target);
};

#endif