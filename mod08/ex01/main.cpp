/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:44:58 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/25 05:29:24 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int	main(void)
{
	Span span(4);

	span.addNumber(1);
	span.addNumber(5);
	span.addNumber(-79);
	span.addNumber(-80);

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
	return (0);
}