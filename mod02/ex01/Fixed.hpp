/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:23 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/09 01:06:56 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
