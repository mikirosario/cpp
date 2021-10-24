/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:27:47 by miki              #+#    #+#             */
/*   Updated: 2021/10/24 18:32:26 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define OUT std::cout
#define NL std::endl
#define LINE_SEP "---------------------"

int	main(void)
{
	Array<int> my_array(4);
	Array<char> my_str(12);

	OUT << "CHARACTER ARRAY TESTS" << NL
	<< LINE_SEP << NL
	<< "Bracket Operator Overload and Size Method: " << NL
	<< " ";
	char lazy[] = "Hello World!";
	//Lazily assign each character in the lazy string to the bytes of my_str.
	for(size_t lazy_assign = 0; lazy_assign < 12; ++lazy_assign)
		my_str[lazy_assign] = lazy[lazy_assign];
	//Print out my_str, lazily using the size method to get the size over and over again. xD
	for (size_t i = 0; i < my_str.size(); ++i)
		OUT << my_str[i];
	OUT << NL
	<< "Copy Constructor Test (Deep Copy): " << NL
	<< " ";
	Array<char> empty_str(my_str);
	//Print out empty_str
	for (size_t i = 0; i < empty_str.size(); ++i)
		OUT << empty_str[i];
	OUT << NL
	<< "Changing Copy (Changing All Characters to Upper Case).";
	//Change all characters to upper case in copied string
	for (size_t i = 0; i < empty_str.size(); ++i)
		empty_str[i] = std::toupper(empty_str[i]);
	OUT << NL
	<< "Reprint Copied String: " << NL
	<< " ";
	//Print out copied string
	for (size_t i = 0; i < empty_str.size(); ++i)
		OUT << empty_str[i];
	OUT << NL
	<< "Reprint Original String: " << NL
	<< " ";
	for (size_t i = 0; i < my_str.size(); ++i)
		OUT << my_str[i];
	OUT << NL << LINE_SEP << NL

	<< NL << "INTEGER ARRAY TESTS" << NL
	<< LINE_SEP << NL
	<< "Bracket Operator Overload and Size Method: " << NL
	<< " ";
	my_array[0] = 2;
	my_array[1] = 0;
	my_array[2] = 2;
	my_array[3] = 1;
	for (size_t i = 0; i < my_array.size(); ++i)
		OUT << my_array[i];
	OUT << NL
	<< "Assignment Operator Overload: " << NL
	<< "Assigning my_array to empty_array." << NL;
	Array<int> empty_array(4);
	empty_array = my_array;
	OUT << "Print empty_array: " << NL
	<< " ";
	for (size_t i = 0; i < empty_array.size(); ++i)
		OUT << empty_array[i];
	OUT << NL << LINE_SEP << NL

	<< NL << "OUT OF BOUNDS ACCESS TESTS" << NL
	<< LINE_SEP << NL
	<< "Empty Array Access Attempt Tests: " << NL
	<< " ";
	Array<int> empty1;
	Array<char> empty2(0);
	try {
		empty1[0] = 1;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	OUT << NL
	<< " ";
	try {
		empty2[0] = 1;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	OUT << NL
	<< "Existing Array Out of Bounds Access Attempt Tests: " << NL
	<< " ";
	try {
		OUT << my_str[13];
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	OUT << NL
	<< " ";
	try {
		OUT << my_array[-1];
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	OUT << NL << LINE_SEP << NL;
	return (0);
}
