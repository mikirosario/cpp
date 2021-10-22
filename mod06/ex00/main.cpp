/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:11 by miki              #+#    #+#             */
/*   Updated: 2021/10/22 15:41:47 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"
#include <iterator>
#include <cstdlib>
#include <string>

int		isSign(char const & c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

/*
** This function will identify the type (double or float) of a psuedonumber like
** nan or inf passed as a string. Why would anyone do this? I dunno. The subject
** says it's for fun. xD
*/

int	pseudoNumberType(std::string const & str)
{
	std::string	const pseudo_lits[4] = {"inff","nanf","inf","nan"};
	//bool type = 0; //0 == none, 2 == float, 3 == double

	for (size_t i = 0; i < 4; ++i)
		if (str.compare(pseudo_lits[i]) == 0)
			return (i < 2 ? t_float : t_double);
	return (t_not_a_number);
}

/*
** This function will identify the number in a literal string as either an INT,
** a DOUBLE or a FLOAT, returning 1 for INT, 2 for DOUBLE and 3 for FLOAT. If
** the string is none of these things, it will return 0.
**
** An INT must be a string of only digits followed by a null terminator.
**
** A DOUBLE must be a string of only digits followed by a single point and
** another series of only digits followed by a null terminator, or a point
** followed by a series of only digits followed by a null terminator, (which
** will be interpreted as 0.FRACTION).
**
** A FLOAT must be a string of only digits followed by a single point and
** another series of only digits, followed by an 'f' and a null terminator,
** or a string of only digits followed by an 'f' and a null terminator (which
** will be interpreted as INT.0f), or a point followed by a string of only digits
** followed by an 'f' and a null terminator (which will be interpreted as
** 0.FRACTIONf).
**
** Valid INT:		#
** Valid DOUBLES:	#.# .#
** Valid FLOATS:	#.#f .#f #f
*/

int		numberType(std::string const & str)
{
	size_t	i = 0;
	int		type = 0; //0 = NaN, 1 = int, 2 = double, 3 = float

	for ( ; std::isdigit(str[i]); ++i) //digits are OK
	{
	}
	if (str[i] == '\0') //isInt
		return (t_int);
	else if (str[i] == '.') //a single point is OK
		++i;
	for ( ; std::isdigit(str[i]); ++i) //digits after a point are OK
	{
	}
	if (str[i] == '\0') //isDouble
		type = t_double;
	else if (str[i] == 'f' && str[i + 1] == '\0') //isFloat
		type = t_float;
	return (type);
}



bool	skipSpaces(std::string::iterator & index)
{
	int no_op = 0;
	for ( ; std::isspace(*index); ++index ) //dereferencing iterator not doing what i assumed??
	{
		//DEBUG CODE
		if (1)
			no_op++;
		//DEBUG CODE
	}
	return (true);
}

/*
** Return value 1 == negative sign; return value 0 == positive sign.
*/

bool	determineSign(std::string::iterator & index)
{
	int global_sign = 0;
	skipSpaces(index);
	for (int sign; (sign = isSign(*index)); ++index)
	{
			global_sign += sign;
			skipSpaces(index);
	}
	return ((global_sign < 0));
}

/*
** This function will parse the string passed as arg. If it is a valid number,
** its type will be returned. If not, 0 will be returned.
**
** Multiple '+' and '-' signs will be tallied and replaced with a final sign.
**
** Spaces before the number will be ignored.
**
** Valid INT:		#
** Valid DOUBLES:	#.# .#
** Valid FLOATS:	#.#f .#f #f
*/

int							parse_argument(std::string & arg)
{
	std::string::iterator begin = arg.begin();
	std::string::iterator index = arg.begin();
	//std::string::iterator end = arg.end();
	char	sign;
	int		type;

	sign = determineSign(index) ? '-' : '+';;
	arg.erase(begin, index); //garbage disposal
	
	if ((type = pseudoNumberType(arg)) || (type = numberType(arg)))
		arg.insert(arg.begin(), sign); //replace signs with final sign
	return (type);
}

int			main(int argc, char const **argv) //My first implicit cast xD
{	
	std::string	arg;
	int			type;
	int			numi =0;
	float		numf =0;
	double		numd =0;

	if (argc != 2 || *argv[1] == '\0')
	{
		std::cerr << "Pass a single number as a parameter, (i.e. 42)" << std::endl;
		return (0);
	}
	arg = argv[1];
	type = parse_argument(arg);
	switch (type)
	{
		case t_int:
			numi = std::atoi(arg.c_str()); //stoi is banned, because it's c++11 :p
			break;
		case t_float:
			numf = std::atof(arg.c_str());
			break;
		case t_double:
			numd = std::atof(arg.c_str());
			break;
		default:
			std::cerr << "That was not a number." << std::endl;
			return (1);
	}
	//DEBUG TEST
	std::cout << "Int: " << numi << ", Float: " << numf << ", Double: " << numd << std::endl;
	return (0);
}