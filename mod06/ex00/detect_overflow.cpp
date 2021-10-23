/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_overflow.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:56:26 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/23 17:25:23 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"
#ifdef __linux__
# include <climits>
#endif
#include <sstream>
#include <iomanip>

#define PREC_ZERO std::fixed << std::setprecision(0)

/*
** This function measures integer length of a number represented by characters
** and passed as a string.
*/

static size_t	intLen(std::string const & str)
{
	size_t	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

/*
** This function detects overflows given an absolute number passed as a
** character string, a conversion type and a sign.
**
** Wow! This turned out to be a lot more complicated than I thought. xD
**
** We don't bother to check chars because they need to be input as characters,
** not integers, so they can't overflow.
**
** The relevant max number is derived from the type and the sign.
**
** I've learned that floating point numbers (floats and doubles) are symmetrical
** with the IEEE 754 standard, so the lowest value of a double is just -DBL_MAX.
** At DBL_MAX, though, it gets so imprecise that the poor 'puter will literally
** round differences of trillions to the DBL_MAX. I gave up before discovering
** how big a difference from DBL_MAX would have to be to finally register. xD
**
** We use stringstream to pass the value to string. (C++11 tools are banned by
** the cursus). I'm sure there must be a more elegant way to do this, even in
** C++98, but this is already extra work not required by the exercise so... xD
**
** If the max number is negative we need to remove the '-' sign. To do that with
** the string stream it seems we'd need to either get the string reference,
** erase it and pass the result back into the stream, or manipulate the stream
** index so the returned string starts after the '-'. I don't really like the
** stringstream, so I just copy the string into a normal string. :p
**
** For the purposes of determining float or double overflows we are only
** interested in integer range. The stringstream is set to return the DBL_MAX
** and FLT_MAX with 0 precision for this reason. We also use a special strlen
** called intLen which will stop counting upon hitting a '.' to measure our
** number.
**
** Following that, it's straightforward. For number lengths less than the max
** number length, we return false for no overflow. For number lengths greater
** than the max number length, we return true for overflow. For numbers of
** equal length we check every number character against its corresponding max
** number character and return true if any is greater, and false if all are less
** than or equal. Since we know both strings are the same length, as we leave
** the function early otherwise, this last check only confirms the num_index
** address against the num_end address.
*/

bool		isOverflow(std::string const & num, int	type, char sign)
{
	std::stringstream 			s_max;
	std::string 				max;
	std::string::const_iterator num_index = num.begin();
	std::string::const_iterator max_index;
	std::string::const_iterator max_end;
	size_t						num_len_int;
	size_t						max_len_int;

	if (type == t_int)
		(sign == '-' ? s_max << INT_MIN : s_max << INT_MAX);
	else if (type == t_float)
		(sign == '-' ? s_max << PREC_ZERO << -__FLT_MAX__ : s_max << PREC_ZERO << __FLT_MAX__); //Floats and doubles are symmetrical in IEEE 754 :)
	else if (type == t_double)
		(sign == '-' ? s_max << PREC_ZERO << -__DBL_MAX__ : s_max << PREC_ZERO << __DBL_MAX__);
	max = s_max.str(); //Either this or pass the string with the erased '-' back into the stream later... might as well just copy it. :p
	if (max[0] == '-')
		max.erase(0, 1);
	//We're only interested in integer max and integer min for floating points.
	//They lose fractional precision long before they lose integer precision.
	//So we just want integer lengths.
	num_len_int = intLen(num);
	max_len_int = intLen(max);
	if (num_len_int < max_len_int)
		return (false);
	else if (num_len_int > max_len_int)
		return (true);
	max_index = max.begin();
	max_end = max.end();
	for (size_t i = 0; i < max_len_int ; ++i, ++num_index, ++max_index)
		if (*num_index > *max_index)
			return (true);
	return (false);
}
