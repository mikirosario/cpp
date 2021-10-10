/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:23 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/09 20:03:27 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int					_value;
		static const int	_fractional_bits = 8;
	public:
		Fixed();
		Fixed(Fixed const &value);
		~Fixed();

		Fixed	&operator=(Fixed const &right_value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);		
};

#endif