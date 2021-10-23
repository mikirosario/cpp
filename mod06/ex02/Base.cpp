/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:26:06 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 17:40:06 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <unistd.h>

Base::~Base(void)
{
}

Base *	generate(void)
{
	int	base_class;
	struct timespec tonti;
	enum base_classes
	{
		A_class = 0,
		B_class,
		C_class
	};

	usleep(50); //Increase nanosecond randomness on school Macs. xD
	clock_gettime(CLOCK_REALTIME, &tonti);
	srand(tonti.tv_nsec);
	base_class = rand() % 3;
	if (base_class == A_class)
		return (new A);
	else if (base_class == B_class)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception & e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception & e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception & e)
	{
	}
}
