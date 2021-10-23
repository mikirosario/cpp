/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:18:30 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 22:07:13 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template<typename T>
void		swap(T & a, T & b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const &	min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

template<typename T>
T const &	max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

#endif
