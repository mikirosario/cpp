/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:52:44 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/10 06:40:36 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int	main(void)
{
	Fixed a(1.25f);
	Fixed b(1.5f);
	Fixed c(5.6f);
	Fixed d(7.9f);
	Fixed e(1);
	Fixed f(1);
	Fixed g(42.42f);
	Fixed h(21.21f);
	Fixed i(4000000.25f);
	Fixed j(-6.8f);
	Fixed k(-1.2f);
	float cf = 5.6f;
	float df = 7.9f;
	float jf = -6.8f;
	float kf = -1.2f;

	std::cout << std::fixed << std::setprecision(8) << std::boolalpha;

	//Sanity check
	std::cout << "Sanity Check" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "i is " << i << std::endl;
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "a - b is " << a - b << std::endl;
	std::cout << "a * b is " << a * b << std::endl;
	std::cout << "i * 2 is " << i * 2 << std::endl;
	std::cout << "a / 1 is " << a / 1 << std::endl;
	std::cout << "i / a is " << i / a << std::endl;
	std::cout << std::endl;

	//Float precision comparison
	std::cout << "Float precision comparison" << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "cf is " << cf << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "df is " << df << std::endl;
	std::cout << std::endl;

	//Float addition comparison
	std::cout << "Float addition precision comparison" << std::endl;
	std::cout << "c + d is " << c + d << std::endl;
	std::cout << "cf + df is " << cf + df << std::endl;
	std::cout << std::endl;

	//Float subtraction comparison
	std::cout << "Float subtraction precision comparison" << std::endl;
	std::cout << "c - d is " << c - d << std::endl;
	std::cout << "cf - df is " << cf - df << std::endl;
	std::cout << std::endl;

	//Float multiplication comparison
	std::cout << "Float multiplication precision comparison" << std::endl;
	std::cout << "c * d is " << c * d << std::endl;
	std::cout << "cf * df is " << cf * df << std::endl;
	std::cout << "j * c is " << j * c << std::endl;
	std::cout << "jf * cf is " << jf * cf << std::endl;
	std::cout << std::endl;

	//Float division comparison
	std::cout << "Float division precision comparison" << std::endl;
	std::cout << "c / d is " << c / d << std::endl;
	std::cout << "cf / df is " << cf / df << std::endl;
	std::cout << "j / k is " << j / k << std::endl;
	std::cout << "jf / kf is " << jf / kf << std::endl;
	std::cout << std::endl;

	//Comparison operators
	std::cout << "Comparison operators" << std::endl;
	std::cout << "is " << a << " <  " << b << "? " << (a < b) << std::endl;
	std::cout << "is " << a << " >  " << b << "? " << (a > b) << std::endl;
	std::cout << "is " << a << " == " << b << "? " << (a == b) << std::endl;
	std::cout << "is " << b << " == " << b << "? " << (b == b) << std::endl;
	std::cout << "is " << a << " != " << b << "? " << (a != b) << std::endl;
	std::cout << "is " << b << " != " << b << "? " << (b != b) << std::endl;
	std::cout << "is " << a << " <= " << b << "? " << (a <= b) << std::endl;
	std::cout << "is " << a << " >= " << b << "? " << (a >= b) << std::endl;
	std::cout << "is " << b << " <= " << b << "? " << (b <= b) << std::endl;
	std::cout << "is " << b << " >= " << b << "? " << (b >= b) << std::endl;
	std::cout << std::endl;

	//Min/max function tests
	std::cout << "Min/max function tests" << std::endl;
	std::cout << "min of " << a << " and " << b << " is " << (Fixed::min(a, b)) << std::endl;
	std::cout << "max of " << a << " and " << b << " is " << (Fixed::max(a, b)) << std::endl;
	std::cout << "const min of " << g << " and " << h << " is " << (Fixed::min(g, h)) << std::endl;
	std::cout << "const max of " << g << " and " << h << " is " << (Fixed::max(g, h)) << std::endl;
	std::cout << std::endl;

	//Epsilon
	std::cout << "Epsilon " << std::endl;
	std::cout << "Epsilon is " << Fixed::getEpsilon() << std::endl;
	std::cout << "Epsilon + Epsilon is: " << (Fixed::getEpsilon() + Fixed::getEpsilon()) << std::endl;
	std::cout << std::endl;

	//Prefix and postfix operations
	std::cout << "Prefix and postfix operations" << std::endl;
	std::cout << std::left;;
	std::cout << "e is " << e << " ++e is " << std::setw(10) << ++e << " e is " << e << std::endl;
	std::cout << "f is " << f << " f++ is " << std::setw(10) << f++ << " f is " << f << std::endl;
	std::cout << "e is " << e << " --e is " << std::setw(10) << --e << " e is " << e << std::endl;
	std::cout << "f is " << f << " f-- is " << std::setw(10) << f-- << " f is " << f << std::endl;
	return (0);
}
