/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:52:44 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/10 18:10:41 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "bsp.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point inside(10, 15);
	Point outside(30, 15);
	float epsilon = Fixed::getEpsilon().toFloat();
	//Point edge(0.0f - epsilon, 0.0f - epsilon);
	Point edge(0.1f, 0.1f);

	std::cout << "Epsilon: " << epsilon << std::endl;
	if (bsp(a, b, c, inside))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	if (bsp(a, b, c, outside))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	if (bsp(a, b, c, edge))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	return (0);
}