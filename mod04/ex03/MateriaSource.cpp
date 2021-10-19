/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:53:51 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 02:36:18 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void	MateriaSource::replace_known_materia(MateriaSource const &src)
{
	size_t i;

	for (i = 0; i < MAX_KNOWN_MATERIA; i++)
	{
		if (this->_known_materia[i])
		{
			delete this->_known_materia[i];
			this->_known_materia[i] = NULL;
		}
	}
	for (i = 0; i < MAX_KNOWN_MATERIA; i++)
	{
		if (src._known_materia[i])
			this->_known_materia[i] = src._known_materia[i]->clone();
	}
}


MateriaSource::MateriaSource(void) : _known_materia()
{
}

MateriaSource::MateriaSource(MateriaSource const &src) : _known_materia()
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i < MAX_KNOWN_MATERIA; i++)
		if (_known_materia[i])
		{
			delete _known_materia[i];
			_known_materia[i] = NULL;
		}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &src)
{
	this->replace_known_materia(src);
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *materia)
{
	size_t	i;

	if (materia == NULL)
		return ;
	for (i = 0; _known_materia[i]; i++)
		if (i == MAX_KNOWN_MATERIA)
			return ;
	_known_materia[i] = materia;
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	size_t	i;
	for (i = 0; i < MAX_KNOWN_MATERIA; i++)
		if (_known_materia[i] && _known_materia[i]->getType().compare(type) == 0) //if a materia is stored here and its type is the same as the argument
			return (_known_materia[i]); //return the pointer to it
	return (NULL);
}