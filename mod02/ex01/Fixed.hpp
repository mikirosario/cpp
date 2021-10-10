/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:23 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/09 20:03:47 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <fstream>

class Fixed
{
	private:
		int					_value;
		int static const	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(Fixed const &value);
		Fixed(float const float_value);
		Fixed(int const value);
		~Fixed();

		Fixed			&operator=(Fixed const &right_value);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
};

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed_point_value);

#endif