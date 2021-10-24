/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:58:36 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/25 01:17:10 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <vector>

template<typename T>
int	*	easyfind(T & container, int n)
{
	 //T::iterator is dependent; I know it's another type, but as far as
	 //Compiler knows, iterator could be an integer, a function or anything, so
	 //I need to explicitly tell Compiler it's a typename so it knows what to do
	 //with 'it' (use as reference to instantiated T::iterator type).
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		if (*it == n)
			return (&(*it));
	return (NULL);
}

#endif