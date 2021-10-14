/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:23 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 16:01:32 by mrosario         ###   ########.fr       */
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
		Fixed(void);
		Fixed(Fixed const &value);
		~Fixed(void);

		Fixed	&operator=(Fixed const &right_value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);		
};

#endif