/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:11 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 17:43:05 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"
//#include <iterator>
//#include <cstdlib>
#ifdef __linux__
# include <cstring> //need this for memset at home on Linux
#endif
//#include <string>
#include <iomanip>

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


/*
** Skips all spaces in a string pointed to by an iterator, advancing the
** iterator. Assumes strings are null-terminated!
*/

void	skipSpaces(std::string::iterator & index)
{
	for ( ; std::isspace(*index); ++index )
	{
	}
}


/*
** This function skips all spaces at the end of a string, starting from the
** penultimate character, and returns an iterator pointing to the first space
** at the end of the string.
*/

std::string::iterator	backSkipSpaces(std::string & str)
{
	std::string::iterator	index = str.end();
	std::string::iterator	begin = str.begin();
	if (index == begin)
		return (index);
	else
		--index;
	for ( ; std::isspace(*index) ; --index )
		if (index == begin)
			return (index);
	return (index + 1);
}

/*
** This function will determine the sign of a literal number by examining the
** part of the string before the number.
**
** For every '+' sign a number will be considered more positive, and for every
** '-' sign it will be considered more negative. Unsigned numbers are considered
** positive.
**
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

int		detectCharType(std::string const & str)
{
	size_t	i = 0;
	if (str[i++] == '\'')
		if (str[++i] == '\'')
			if (str[++i] == '\0')
				return (t_char);
	return (0);
}

/*
** This function will parse the string passed as arg. If it is a valid number,
** its type will be returned. If not, 0 will be returned.
**
** Multiple '+' and '-' signs will be tallied and replaced with a single sign.
**
** Spaces before or after the number will be ignored.
**
** 
** Valid INT:		#
** Valid DOUBLES:	#.# .#
** Valid FLOATS:	#.#f .#f #f
*/

int							parse_argument(std::string & arg)
{
	std::string::iterator begin = arg.begin();
	std::string::iterator index;
	char	sign;
	int		type;

	index = backSkipSpaces(arg);
	arg.erase(index, arg.end()); //erase trailing spaces
	index = begin;
	skipSpaces(index); //erase preceding spaces
	arg.erase(begin, index);
	type = detectCharType(arg);
	if (type != t_char)
	{
		sign = determineSign(index) ? '-' : '+';
		arg.erase(begin, index); //garbage disposal
		if ((type = pseudoNumberType(arg)) || (type = numberType(arg)))
		{
			if (isOverflow(arg, type, sign))
			{
				type = 0;
				std::cout << "Your number is too big to fit in the specified type. Choose a bigger type or write a smaller number." << std::endl;
			}
			else
				arg.insert(arg.begin(), sign); //replace any preceding signs with single sign
		}
	}
	return (type);
}

bool		badBit(char const & flag, int const & bit)
{
	return (((flag >> bit) & 1));
}

void		printresults(t_conversion_data & data)
{
	//data indicating whether int, float or chr conversions failed are stored in flag
	std::cout << std::fixed << std::setprecision(8)
	<< "Char: ";
	if (badBit(data.flag, t_char))
		std::cout << IMPOSSIBLE;
	else if (!std::isprint(data.chr))
		std::cout << UNPRINTABLE;
	else
		std::cout << data.chr;
	NEWLN;
	std::cout << "Int: ";
	if (badBit(data.flag, t_int))
		std::cout << IMPOSSIBLE;
	else
		std::cout << data.numi;
	NEWLN;
	std::cout << "Float: ";
	if (badBit(data.flag, t_float))
		std::cout << IMPOSSIBLE;
	else
		std::cout << data.numf;
	NEWLN;
	std::cout << "Double: " << data.numd << std::endl;
}

int			main(int argc, char const **argv) //My first implicit cast xD
{	
	std::string			arg;
	t_conversion_data	data;

	std::memset(&data, 0, sizeof(t_conversion_data));

	if (argc != 2 || *argv[1] == '\0')
	{
		std::cerr << "Pass a single character enclosed in simple commas ' ' or a number as a parameter, (i.e. 42, 'y')" << std::endl;
		return (0);
	}
	arg = argv[1];
	data.type = parse_argument(arg);
	switch (data.type)
	{
		case t_int:
			data.numi = std::atoi(arg.c_str()); //stoi is banned, because it's c++11 :p
			data.numf = static_cast<float>(data.numi);
			data.numd = static_cast<double>(data.numi);
			tryConvertToChar(data.chr, data.numi, data.flag);
			break;
		case t_float:
			data.numf = std::atof(arg.c_str());
			data.numd = static_cast<double>(data.numf);
			tryConvertToChar(data.chr, data.numf, data.flag);
			tryConvertToInt(data.numi, data.numf, data.flag);
			break;
		case t_double:
			data.numd = std::atof(arg.c_str());
			tryConvertToChar(data.chr, data.numd, data.flag);
			tryConvertToInt(data.numi, data.numd, data.flag);
			tryConvertToFloat(data.numf, data.numd, data.flag);
			break;
		case t_char:
			data.chr = arg[1];
			data.numi = static_cast<int>(arg[1]);
			data.numf = static_cast<float>(arg[1]);
			data.numd = static_cast<double>(arg[1]);
			break;
		default:
			std::cerr << "That was not a number or valid character." << std::endl;
			return (1);
	}
	printresults(data);
	return (0);
}
