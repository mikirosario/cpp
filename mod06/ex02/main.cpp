/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:57:25 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 03:30:59 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>


int	main(void)
{
	Base * ptr1;
	Base * ptr2;
	Base * ptr3;
	Base * ptr4;
	
	ptr1 = generate();
	ptr2 = generate();
	ptr3 = generate();
	ptr4 = generate();

	std::cout << "DYNAMIC CAST BY POINTER" << std::endl;
	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	identify(ptr4);

	std::cout << std::endl;
	std::cout << "DYNAMIC CAST BY REFERENCE" << std::endl;
	identify(*ptr1);
	identify(*ptr2);
	identify(*ptr3);
	identify(*ptr4);
	return (0);
}
