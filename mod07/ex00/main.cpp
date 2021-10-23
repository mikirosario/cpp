/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:15:51 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/23 22:52:51 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#define OUT std::cout
#define NL std::endl
#define LINE_SEP "-------------------"

int	main(int const argc, char const **argv)
{
	if (argc == 2 && std::string(argv[1]).compare("school") == 0)
		goto school_test;
	else if (argc > 2)
	{
		OUT << "Pass 'school' as an argument for the school tests, or run with no arguments for my tests" << NL;
		return (1);
	}

	{
		int 	a = 1;
		int 	b = 2;
		char	c = 'c';
		char	d = 'd';
		char *	e = &c;
		char *	f = &d;
		float	g = 42.42;
		float	h = 2021.21;
		char 	i[2];

		OUT
		<< "SWAP CHECK" << NL << LINE_SEP << NL
		<< "Int Swap:" << NL
		<< "a: " << a << ", b: " << b << NL
		<< "swap(a, b)" << NL;
		swap(a, b);
		OUT << "a: " << a << ", b: " << b << NL;

		OUT << NL
		<< "Pointer Swap: " << NL
		<< "*e: " << *e << ", *f: " << *f << NL
		<< "swap(e, f)" << NL;
		swap(e, f);
		OUT << "*e: " << *e << ", *f: " << *f << NL;

		OUT << NL
		<< "Char Swap: " << NL
		<< "c: " << c << ", d: " << d << NL
		<< "swap(c, d)" << NL;
		swap(c, d);
		OUT << "c: " << c << ", d: " << d << NL;
		
		OUT << NL
		<< "Float Swap: " << NL
		<< "g: " << g << ", h: " << h << NL
		<< "swap(g, h)" << NL;
		swap(g, h);
		OUT << "g: " << g << ", h: " << h << NL
		<< LINE_SEP << NL;

		OUT << NL
		<< "MAX CHECK" << NL << LINE_SEP << NL
		<< "Int Max Check: "
		<< "a: " << a << ", b: " << b << NL
		<< "max(a, b): " << max(a, b) << NL
		<< NL
		<< "Char Max Check: "
		<< "c: " << c << ", d: " << d << NL
		<< "max(c, d): " << max(c, d) << NL
		<< NL
		<< "Float Max Check: "
		<< "g: " << g << ", h: " << h << NL
		<< "max(g, h): " << max(g, h) << NL
		<< NL
		<< "Pointer Max Check: "
		<< "&i[0]: " << reinterpret_cast<void *>(&i[0]) << ", &i[1]: " << reinterpret_cast<void *>(&i[1]) << NL
		<< "max(&i[0], &i[1]): " << reinterpret_cast<void *>(max(&i[0], &i[1])) << NL
		<< LINE_SEP << NL << NL
		
		<< "MIN CHECK" << NL << LINE_SEP << NL
		<< "Int Min Check: "
		<< "a: " << a << ", b: " << b << NL
		<< "min(a, b): " << min(a, b) << NL
		<< NL
		<< "Char Min Check: "
		<< "c: " << c << ", d: " << d << NL
		<< "min(c, d): " << min(c, d) << NL
		<< NL
		<< "Float Min Check: "
		<< "g: " << g << ", h: " << h << NL
		<< "min(g, h): " << min(g, h) << NL
		<< NL
		<< "Pointer Min Check: "
		<< "&i[0]: " << reinterpret_cast<void *>(&i[0]) << ", &i[1]: " << reinterpret_cast<void *>(&i[1]) << NL
		<< "min(&i[0], &i[1]): " << reinterpret_cast<void *>(min(&i[0], &i[1])) << NL
		<< LINE_SEP << NL;
		return (0);
	}

	school_test:
	{
		int a = 2;
		int b = 3;
	
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}