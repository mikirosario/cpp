/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:41:02 by miki              #+#    #+#             */
/*   Updated: 2021/10/10 08:51:15 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

/*
** This is just an implementation of the GeeksforGeeks method, adapted to use
** my Fixed class. ;)
** https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
*/

static Fixed	getTriangleArea(Point const &a, Point const &b, Point const &c)
{
	return((((a.getX() * (b.getY() - c.getY()))
	+ (b.getX() * (c.getY() - a.getY()))
	+ (c.getX() * (a.getY() - b.getY()))) / 2.0f));
}

/*
** Just an abs for my fixed point class.
*/

static Fixed	fixabs(Fixed value)
{
	if (value < 0)
		value.setRawBits(-value.getRawBits());
	return (value);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;

	A = fixabs(getTriangleArea(a, b, c));
	A1 = fixabs(getTriangleArea(point, a, b));
	A2 = fixabs(getTriangleArea(point, b, c));
	A3 = fixabs(getTriangleArea(point, a, c));

	// // DEBUG CODE
	// std::cout << "A: " << A << std::endl;
	// std::cout << "A1: " << A1 << std::endl;
	// std::cout << "A2: " << A2 << std::endl;
	// std::cout << "A3: " << A3 << std::endl;
	// // DEBUG CODE

	if (A1 + A2 + A3 == A)
		return (true);
	return (false);
}