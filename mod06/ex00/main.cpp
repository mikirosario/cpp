/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:11 by miki              #+#    #+#             */
/*   Updated: 2021/10/21 18:37:48 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>


int		isSign(char const & c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

bool	isInt(std::string const & str)
{
	for (size_t i = 0; str[i]; i++)
		if (std::isdigit(str[i]) == 0)
			return (false);
	return (true);
}

bool	isFloat(std::string const & str)
{
	bool	decimal_point = false;
	
}

bool	isPseudoLiteral(std::string const & str)
{
	std::string	const pseudo_lits[4] = {"inff","nanf","inf","nan"};
	
}

bool	skipSpaces(std::string::const_iterator & index)
{
	for ( ; std::isspace(*index); ++index )
	{
	}
	return (true);
}

/*
** Return value 1 == negative sign; return value 0 == positive sign.
*/

bool	determineSign(std::string::const_iterator & index)
{
	int global_sign = 0;
	for (int sign; skipSpaces(index) || (sign = isSign(*index)); ++index)
			global_sign += sign;
	return ((global_sign < 0));
}

bool							parse_argument(std::string & arg)
{
	std::string::const_iterator begin = arg.begin();
	std::string::const_iterator index = arg.begin();
	std::string::const_iterator end = arg.end();
	char	sign;
	
	sign = determineSign(index) ? '-' : '+';
	if (index == end)
		return (false);
	arg.erase(begin, index); //garbage disposal
	arg.insert(arg.begin(), sign); //replace signs with final sign
	
	if (isNumber(arg) || isPseudoLiteral(arg))
	

}

int			main(int argc, char const **argv) //My first implicit cast xD
{	
	if (argc != 2)
	{
		std::cerr << "Pass a single number as a parameter, (i.e. 42)"
	}
	return (0);
}