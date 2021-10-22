/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_conversion.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:03:04 by miki              #+#    #+#             */
/*   Updated: 2021/10/22 21:27:15 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_H
# define SCALAR_CONVERSION_H

#include <iostream>

#define UNPRINTABLE "Unprintable"
#define IMPOSSIBLE "Impossible"
#define NEWLN std::cout << std::endl;

typedef struct	s_conversion_data
{
	int			type;
	int			numi;
	float		numf;
	double		numd;
	char		chr;
	char		flag;
}				t_conversion_data;

enum	types {
	t_not_a_number = 0,
	t_int,
	t_double,
	t_float,
	t_char
};

void	tryConvertToChar(char & c, int & i, char & flag);
void	tryConvertToChar(char & c, float & f, char & flag);
void	tryConvertToChar(char & c, double & d, char & flag);
void	tryConvertToInt(int & i, float & f, char & flag);
void	tryConvertToInt(int & i, double & d, char & flag);
void	tryConvertToFloat(float & f, double & d, char & flag);
bool	isOverflow(std::string const & str, int type, char sign);

#endif