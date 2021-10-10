/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:41:02 by miki              #+#    #+#             */
/*   Updated: 2021/10/10 21:11:50 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Point.hpp"



static Fixed	getTriangleArea(Point const &a, Point const &b, Point const &c)
{
	return ((Fixed)0.5f * ((b.getY() * -1.0f) * c.getX() + a.getY()
	* ((b.getX() * -1.0f) + c.getX()) + a.getX()
	* (b.getY() - c.getY()) + b.getX() * c.getY()));
}

/*
** This is the barycentric implementation. It creates a problem because of the
** division of 1.0 by 2(triangle area), which very easily returns a result
** smaller than epsilon in my fixed point class. Consequently, I do that
** calculation and the following one with floats. The following calculation
** has to be done with floats as well, because its left operand is the result
** of the aforementioned division and a Fixed may not be able to store it if it
** is < epsilon. The rest of the calculations are done with Fixeds.
**
** 0.001953125f (approx.) is the minimum point coordinate detectable by the
** algorithm using my fixed numbers, because it will be rounded up to epsilon
** (0.00390625). Anything less will be rounded down to 0 and be equivalent to 0
** distance. Hence coordinate 1.001953125 is saved as 1.00390625, and coordinate
** 1.001953124 is saved as 1.0 within the point objects.
**
** This yields a minimum s and t of 0.00013021.
**
** This implementation considers edge cases as outside the triangle, so there is
** effectively a boundary of thickness epsilon (0.00390625) INSIDE the triangle
** That is my interpretation of what the assignment's subject requests verbatim:
**
** "The return value is True if the point is inside the triangle, otherwise, the
** return value should be False. This means that if the point is a vertex or a
** point that is on the edge, the return value should be False."
**
** http://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html
*/

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed Area2 = (getTriangleArea(a, b, c) * 2); //Area pre-multiplied
	float s;
	float t;

	//Initial division result often smaller than epsilon, so I need to do it with floats.
	s = (1.0f / Area2.toFloat()) * ( a.getY() * c.getX() - a.getX() * c.getY()
	+ (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX())
	* point.getY()).toFloat();
	t = (1.0f / Area2.toFloat()) * ( a.getX() * b.getY() - a.getY() * b.getX()
	+ (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX())
	* point.getY()).toFloat();
	std::cout << std::fixed << std::setprecision(8);
	std::cout << "s: " << s << " t: " << t << std::endl;
	if (0 < s && s < 1
		&& 0 < t && t < 1
		&& s + t < 1)
		return (true);
	return (false);
}
