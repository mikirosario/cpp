/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:23 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/10 05:38:06 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
#include <fstream>
#define SCALE 8

/*
** It turns out that the consts are almost more complicated than the maths. xD
** Okay, just to remind myself of my const-ness logic:
**
** The _value will potentially go out of scope if its class instance is declared
** in-line, so I need to pass along a copy of the whole instance just in case.
** (Couldn't the nanny-compiler be used to just tell me to broaden the scope of
** my instance? xD?)
**
** For the static consts _fractional_bits and _epsilon this is not necessary.
** Their lifespan is the full duration of the program, therefore, unlike the
** non-statics, I CAN pass them by reference along a chain of operations as
** right_hand_values no problem without worrying about them going out of scope.
**
** For the +, -, etc. overloads, the right_value is const, and the function
** is const, because the member pointed to by the this pointer (this->_value)
** will NOT be modified. For the = overload the function is NOT const because
** this->_value WILL be modified.
**
** Then there is the return value. I debated whether overload return values
** should or should not be const, making (a = b) = c uncompilable or compilable,
** respectively, or likewise c = (a + b)++. After agonizing for awhile I decided
** to go to Google and see what the experts had to say. I found them all at each
** other's throats over the issue.
**
** After reading some gruesome exchanges, I decided I'm in the non-const camp.
** Long live c = (a + b)++! xD
*/

class Fixed
{
	private:
		int					_value;
		static int const	_fractional_bits;
	public:
		Fixed();
		Fixed(Fixed const &value);
		Fixed(float const float_value);
		Fixed(int const value);
		~Fixed();

		//Comparison operator overloads
		bool				operator<(Fixed const &right_value) const;
		bool				operator>(Fixed const &right_value) const;
		bool				operator==(Fixed const &right_value) const;
		bool				operator!=(Fixed const &right_value) const;
		bool				operator<=(Fixed const &right_value) const;
		bool				operator>=(Fixed const &right_value) const;
		//Arithmetic and assignation overloads
		Fixed				&operator=(Fixed const &right_value);
		Fixed				operator+(Fixed const &right_value) const;
		Fixed				operator-(Fixed const &right_value) const;
		Fixed				operator*(Fixed const &right_value) const;
		Fixed				operator/(Fixed const &right_value) const;
		//Pre- and postfix overloads
		Fixed				&operator++(void); //Prefix overload
		Fixed				operator++(int); //Postfix overload
		Fixed				&operator--(void); //Prefix overload
		Fixed				operator--(int); //Postfix overload
		static Fixed		getEpsilon(void);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &value1, Fixed &value2);
		static Fixed		&max(Fixed &value1, Fixed &value2);
		static Fixed const	&min(Fixed const &value1, Fixed const &value2);
		static Fixed const	&max(Fixed const &value1, Fixed const &value2);
};

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed_point_value);

#endif
