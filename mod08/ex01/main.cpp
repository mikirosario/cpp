/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:44:58 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/26 06:59:18 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include "rng.hpp"
#define PRINT std::cout
#define NL std::endl

int	main(void)
{
	Span span(10);

	PRINT << "THREE KNOWN NUMBERS TESTS" << NL
	<< "addNumber Tests" << NL;
	span.addNumber(2);
	span.addNumber(4);
	span.addNumber(14);
	PRINT << NL

	<< "Three Known Numbers Span Methods Test:" << NL
	<< "Longest Span: " << span.longestSpan() << NL
	<< "Shortest Span: " << span.shortestSpan() << NL
	<< NL

	<< "RANDOM NUMBERS FILL TEST" << NL;
	span.randomFill();
	PRINT << NL

	<< "Full Span Exception Test" << NL;
	try
	{
		span.addNumber(2);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	PRINT << NL

	<< "Random Numbers Span Methods Test" << NL;
	std::cout << span.longestSpan() << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	PRINT << NL

	<< "10000 NUMBERS TEST" << NL;
	Span moarnumbers(10000);
	moarnumbers.randomFill();
	moarnumbers.toFile("out");
	PRINT << "wc -l < out.SPAN" << NL;
	system("wc -l < out.SPAN");
	return (0);
}