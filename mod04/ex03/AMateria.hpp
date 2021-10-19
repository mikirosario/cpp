/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:24:35 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 04:30:03 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	const _type;
		AMateria(void);
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);
		AMateria	&operator=(AMateria const &src);
		std::string const	&getType(void) const;
		virtual AMateria 	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
