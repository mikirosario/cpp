/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:41:02 by miki              #+#    #+#             */
/*   Updated: 2021/10/10 18:08:28 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Point.hpp"

//Triangle areas implementation

// /*
// ** This is just an implementation of the GeeksforGeeks method, adapted to use
// ** my Fixed class. ;)
// ** https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
// */

static Fixed	my_getTriangleArea(Point const &a, Point const &b, Point const &c)
{
	return((((a.getX() * (b.getY() - c.getY()))
	+ (b.getX() * (c.getY() - a.getY()))
	+ (c.getX() * (a.getY() - b.getY()))) / 2.0f));
}

// /*
// ** Just an abs for my fixed point class.
// */

// static Fixed	fixabs(Fixed value)
// {
// 	if (value < 0)
// 		value.setRawBits(-value.getRawBits());
// 	return (value);
// }

// bool	bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	A;
// 	Fixed	A1;
// 	Fixed	A2;
// 	Fixed	A3;

// 	A = fixabs(getTriangleArea(a, b, c));
// 	A1 = fixabs(getTriangleArea(point, a, b));
// 	A2 = fixabs(getTriangleArea(point, b, c));
// 	A3 = fixabs(getTriangleArea(point, a, c));

// 	// // DEBUG CODE
// 	// std::cout << "A: " << A << std::endl;
// 	// std::cout << "A1: " << A1 << std::endl;
// 	// std::cout << "A2: " << A2 << std::endl;
// 	// std::cout << "A3: " << A3 << std::endl;
// 	// // DEBUG CODE

// 	if (A1 + A2 + A3 == A)
// 		return (true);
// 	return (false);
// }

static Fixed	getTriangleArea(Point const &a, Point const &b, Point const &c)
{
	return ((Fixed)0.5f * ((b.getY() * -1.0f) * c.getX() + a.getY() * ((b.getX() * -1.0f) + c.getX()) + a.getX() * (b.getY() - c.getY()) + b.getX() * c.getY()));
}

Fixed const	crossProduct(Point const &side, Point const &point)
{
	// Fixed	cx = 0;
	// Fixed	cy = 0;
	Fixed	cz = ((side.getX() * point.getY()) - (side.getY() * point.getX()));

	return (cz);
}

Fixed const dotProduct(Point const &side1, Point const &side2)
{
	Fixed dp;

	dp = ((side1.getX() * side2.getX()) + (side1.getY() * side2.getY()));
	return (dp);
}

/*
** Scratch pad where I ran tests on calculations to find an overflow in my Fixed
** arithmetic that was returning a 0. For future ref.
*/

// bool	bsp(Point const a, Point const b, Point const c, Point const point)
// {
// 	//Fixed Area = getTriangleArea(a, b, c);
// 	//Fixed my_area = my_getTriangleArea(a, b, c);
// 	Fixed Area2 = (getTriangleArea(a, b, c) * 2);
// 	Fixed my_area2 = (my_getTriangleArea(a, b, c) * 2);
// 	Fixed test1float = ( a.getY().toFloat() * c.getX().toFloat() - a.getX().toFloat() * c.getY().toFloat() + (c.getY().toFloat() - a.getY().toFloat()) * point.getX().toFloat() + (a.getX().toFloat() - c.getX().toFloat()) * point.getY().toFloat());
// 	Fixed test1fix = ( a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY());
// 	Fixed test2float = (1.0f / Area2.toFloat());
// 	Fixed test2fix = ((Fixed)1.0f / Area2);
// 	float test3fix = ((Fixed)1.0f / (Fixed)-600).toFloat();
// 	float test3float = (1.0f / -600.0f);
// 	Fixed s;
// 	Fixed t;

// 	//Area multiplied
// 	//s = ((Fixed)1.0f / ((Fixed)2.0f * Area)) * ( a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY());
// 	//t = ((Fixed)1.0f / ((Fixed)2.0f * Area)) * ( a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY());

// 	// s = (1.0f / (2.0f * Area.toFloat())) * ( a.getY().toFloat() * c.getX().toFloat() - a.getX().toFloat() * c.getY().toFloat() + (c.getY().toFloat() - a.getY().toFloat()) * point.getX().toFloat() + (a.getX().toFloat() - c.getX().toFloat()) * point.getY().toFloat());
// 	// t = (1.0f / (2.0f * Area.toFloat())) * ( a.getX().toFloat() * b.getY().toFloat() - a.getY().toFloat() * b.getX().toFloat() + (a.getY().toFloat() - b.getY().toFloat()) * point.getX().toFloat() + (b.getX().toFloat() - a.getX().toFloat()) * point.getY().toFloat());

// 	//Area pre-multiplied
// 	s = (1.0f / Area2.toFloat()) * ( a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY()).toFloat();
// 	t = (1.0f / Area2.toFloat()) * ( a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY()).toFloat();

// 	// s = 1.0f / (Area2.toFloat()) * ( a.getY().toFloat() * c.getX().toFloat() - a.getX().toFloat() * c.getY().toFloat() + (c.getY().toFloat() - a.getY().toFloat()) * point.getX().toFloat() + (a.getX().toFloat() - c.getX().toFloat()) * point.getY().toFloat());
// 	// t = 1.0f / (Area2.toFloat()) * ( a.getX().toFloat() * b.getY().toFloat() - a.getY().toFloat() * b.getX().toFloat() + (a.getY().toFloat() - b.getY().toFloat()) * point.getX().toFloat() + (b.getX().toFloat() - a.getX().toFloat()) * point.getY().toFloat());
// 	// // DEBUG CODE
// 	// std::cout << "A: " << A << std::endl;
// 	// std::cout << "A1: " << A1 << std::endl;
// 	// std::cout << "A2: " << A2 << std::endl;
// 	// std::cout << "A3: " << A3 << std::endl;
// 	// // DEBUG CODE

// 	std::cout << "Area2: " << Area2 << " My area2: " << my_area2 << std::endl;
// 	std::cout << std::fixed << std::setprecision(8);
// 	std::cout << "Float Right Calcs: " << test1float << " Fixed Right Calcs: " << test1fix << std::endl;
// 	std::cout << "Float Left Calcs: " << test2float << " Fixed Left Calcs: " << test2fix << std::endl;
// 	std::cout << "Float Lit Calcs: " << test3float << " Fixed Lit Calcs: " << test3fix << std::endl;
// 	std::cout << "s: " << s << " t: " << t << std::endl;
// 	if ((Fixed)0 < s && s < (Fixed)1
// 		&& (Fixed)0 < t && t < (Fixed)1
// 		&& s + t < (Fixed)1)
// 		return (true);
// 	return (false);
// }


/*
** This is the barycentric implementation. It creates a problem because of the
** division of 1.0 by 2(triangle area), which very easily returns a result
** smaller than epsilon in my fixed point class. Consequently, I do that
** calculation with floats. The rest of the calculations are done with Fixeds,
** and the final multiplication has to be done with floats, because a Fixed
** may not be able to store the left operand if it is < epsilon.
**
** Then we cast the final product back to Fixed. After multiplication it should
** fit in a Fixed again (unless, of course, the distance )
*/


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed Area2 = (getTriangleArea(a, b, c) * 2);
	Fixed my_area2 = (my_getTriangleArea(a, b, c) * 2);
	Fixed s;
	Fixed t;

	//Area pre-multiplied
	//Initial division result often smaller than epsilon, so I need to do it with floats.
	s = (1.0f / Area2.toFloat()) * ( a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY()).toFloat();
	t = (1.0f / Area2.toFloat()) * ( a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY()).toFloat();

	//s = 1.0f / (Area2.toFloat()) * ( a.getY().toFloat() * c.getX().toFloat() - a.getX().toFloat() * c.getY().toFloat() + (c.getY().toFloat() - a.getY().toFloat()) * point.getX().toFloat() + (a.getX().toFloat() - c.getX().toFloat()) * point.getY().toFloat());
	//t = 1.0f / (Area2.toFloat()) * ( a.getX().toFloat() * b.getY().toFloat() - a.getY().toFloat() * b.getX().toFloat() + (a.getY().toFloat() - b.getY().toFloat()) * point.getX().toFloat() + (b.getX().toFloat() - a.getX().toFloat()) * point.getY().toFloat());
	// // DEBUG CODE
	// std::cout << "A: " << A << std::endl;
	// std::cout << "A1: " << A1 << std::endl;
	// std::cout << "A2: " << A2 << std::endl;
	// std::cout << "A3: " << A3 << std::endl;
	// // DEBUG CODE

	std::cout << std::fixed << std::setprecision(8);
	std::cout << "s: " << s << " t: " << t << std::endl;
	if ((Fixed)0 < s && s < (Fixed)1
		&& (Fixed)0 < t && t < (Fixed)1
		&& s + t < (Fixed)1)
		return (true);
	return (false);
}
