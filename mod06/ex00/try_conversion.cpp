/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_conversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:50:52 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/22 23:51:35 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar_conversion.hpp"

void	tryConvertToChar(char & c, int & n, char & flag)
{
	if (CHAR_MIN <= n && n <= CHAR_MAX)
		c = static_cast<char>(n);
	else
		flag |= 1 << t_char;
}

void	tryConvertToChar(char & c, float & n, char & flag)
{
	//int	i = static_cast<int>(f); //need to cast the float for the comparison to make sense anyway, so cast it to an int.
	if (static_cast<float>(CHAR_MIN) <= n && n <= static_cast<float>(CHAR_MAX))
		c = static_cast<char>(n);
	else
			flag |= 1 << t_char;
}

void	tryConvertToChar(char & c, double & n, char & flag)
{
	//int	i = static_cast<int>(d); //need to cast the float for the comparison to make sense anyway, so cast it to an int.
	if (static_cast<double>(CHAR_MIN) <= n && n <= static_cast<double>(CHAR_MAX))
		c = static_cast<char>(n);
	else
			flag |= 1 << t_char;
}

void	tryConvertToInt(int & i, float & n, char & flag)
{
	if (static_cast<float>(INT_MIN) <= n && n <= static_cast<float>(INT_MAX))
		i = static_cast<int>(n);
	else
			flag |= 1 << t_int;
}

void	tryConvertToInt(int & i, double & n, char & flag)
{
	if (static_cast<double>(INT_MIN) <= n && n <= static_cast<double>(INT_MAX))
		i = static_cast<int>(n);
	else
			flag |= 1 << t_int;
}

void	tryConvertToFloat(float & f, double & n, char & flag)
{
	if (static_cast<double>(-__FLT_MAX__) <= n && n <= static_cast<double>(__FLT_MAX__))
		f = static_cast<float>(n);
	else
			flag |= 1 << t_float;
}
