/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:44:58 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/25 10:23:27 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include "rng.hpp"

int	main(void)
{
	Span span(10);

	span.randomFill();

	try
	{
		span.addNumber(2);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << span.longestSpan() << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	span.toFile("out");
	return (0);
}