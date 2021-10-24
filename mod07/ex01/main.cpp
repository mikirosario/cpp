/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:09:45 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/24 21:25:37 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define OUT std::cout
#define NL std::endl

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int	main(void)
{
	char	chr_array[] = {"abcdefghijklmn"};
	size_t	chr_array_size = std::strlen(chr_array);
	int		int_array[2] = {4,2};
	float	float_array[2] = {4.42, 100.1};
	
	OUT << "FUNKY FUNC" << NL;
	for (size_t i = 0; i < chr_array_size; ++i)
		OUT << chr_array[i];
	OUT << NL;
	iter(chr_array, std::strlen(chr_array), funky_func<char>);
	for (size_t i = 0; i < chr_array_size; ++i)
		OUT << chr_array[i];
	OUT << NL

	<< NL;
	for (size_t i = 0; i < 2; ++i)
		OUT << int_array[i];
	OUT << NL;
	iter(int_array, 2, funky_func<int>);
	for (size_t i = 0; i < 2; ++i)
		OUT << int_array[i];
	OUT << NL

	<< NL;
	for (size_t i = 0; i < 2; ++i)
		OUT << float_array[i];
	OUT << NL;
	iter(float_array, 2, funky_func<float>);
		for (size_t i = 0; i < 2; ++i)
		OUT << float_array[i];
	OUT << NL

	<< NL << "HALVE" << NL;
	for (size_t i = 0; i < chr_array_size; ++i)
		OUT << chr_array[i];
	OUT << NL;
	iter(chr_array, std::strlen(chr_array), halve<char>);
	for (size_t i = 0; i < chr_array_size; ++i)
		OUT << chr_array[i];
	OUT << NL

	<< NL;
	for (size_t i = 0; i < 2; ++i)
		OUT << int_array[i];
	OUT << NL;
	iter(int_array, 2, halve<int>);
	for (size_t i = 0; i < 2; ++i)
		OUT << int_array[i];
	OUT << NL

	<< NL;
	for (size_t i = 0; i < 2; ++i)
		OUT << float_array[i];
	OUT << NL;
	iter(float_array, 2, halve<float>);
	for (size_t i = 0; i < 2; ++i)
		OUT << float_array[i];
	OUT << NL

	<< NL << "SCHOOL TEST " << NL;
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- Qué sentido tiene no poder escribir int[] tab. No sería más simple??
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );


	return (0);
}
