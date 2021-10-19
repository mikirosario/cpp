/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:45:11 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 05:00:46 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

#include "IMateriaSource.hpp"

#define MAX_KNOWN_MATERIA 4

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria			*_known_materia[MAX_KNOWN_MATERIA];
		void				replace_known_materia(MateriaSource const &src);
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);
		MateriaSource	&operator=(MateriaSource const &src);
		IMateriaSource	&operator=(IMateriaSource const &src);
		void 			learnMateria(AMateria*);
		AMateria* 		createMateria(std::string const & type);

		//void				replace_known_materia(AMateria * const (&src)[MAX_KNOWN_MATERIA]); //src is a constant reference to an array of AMateria pointers of size MAX_KNOWN_MATERIA
};

#endif
