/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:52:44 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/11 00:56:52 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "bsp.hpp"

/*
** Triangle test. Note:
**
** 0.001953125f (approx.) is the minimum point distance detectable by the
** algorithm using fixed numbers, because it will be rounded up to fixed epsilon
** (0.00390625) by roundf (used by the class). Anything less will be rounded
** down to 0 and be equivalent to 0 distance. Hence coordinate 1.001953125 is
** saved as 1.00390625, and coordinate 1.001953124 is saved as 1.0.
*/

int	main(void)
{
	float epsilon = Fixed::getEpsilon().toFloat();
	Point assign_test;
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point inside(10, 15);
	Point outside(30, 15);
	Point epsilon_times_2_edge(epsilon * 2, epsilon * 2);
	Point epsilon_edge(epsilon, epsilon);
	Point inside_edge(0.001953125f, 0.001953125f);
	Point edge(0.0f, 0.0f);

	assign_test = b;

	std::cout << "Epsilon: " << epsilon << std::endl;
	std::cout << "Assign test: " << assign_test.getX() << ", " << assign_test.getY() << std::endl;
	std::cout << std::endl;
	std::cout << "INSIDE POINT: " << std::endl;
	if (bsp(a, b, c, inside))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "OUTSIDE POINT: " << std::endl;
	if (bsp(a, b, c, outside))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "INSIDE POINT AT 2(EPSILON) FROM THE EDGE: " << std::endl;
	if (bsp(a, b, c, epsilon_times_2_edge))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "INSIDE POINT AT EPSILON FROM THE EDGE: " << std::endl;
	if (bsp(a, b, c, inside_edge))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "INSIDE POINT AT EPSILON/2 FROM THE EDGE: " << std::endl;
	if (bsp(a, b, c, epsilon_edge))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << "OUTSIDE POINT AT < EPSILON/2 FROM THE EDGE: " << std::endl;
	if (bsp(a, b, c, edge))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	return (0);
}
