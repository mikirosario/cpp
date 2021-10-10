/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:19:58 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/10 17:06:46 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//0101 1010 0101 1010 1010 1010 . 0111 1100
//int == 4 bytes == 32 bits
//fractional bits 8
//integer bits 24 (23)
//sign bit 1

//CONSTRUCTORS AND DESTRUCTOR DEFINITIONS//

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(Fixed const &value)
{
	*this = value;
}

Fixed::Fixed(int const int_value)
{
	this->_value = int_value << Fixed::_fractional_bits;
}

//1*2^_fractional_bits
//1*2^8
//256
Fixed::Fixed(float const float_value)
{													//256
	this->_value = (int)roundf(float_value * (float)(1 << Fixed::_fractional_bits));
}

Fixed::~Fixed()
{
}

//MEMBER FUNCTION DEFINITIONS//
//1*2^_fractional_bits
//1*2^8
//256
float			Fixed::toFloat(void) const
{										  //256
	return ((float)this->_value / (float)(1 << Fixed::_fractional_bits));
}

int				Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fractional_bits);
}

int				Fixed::getRawBits(void) const
{
	return (this->_value);
}

void			Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

//Epsilon is a fixed point value whose raw integer bits are equal to 1.
//This is the same as saying it is equal to 1*2^-_fractional_bits
Fixed			Fixed::getEpsilon(void)
{
	Fixed	epsilon;

	epsilon.setRawBits(1);
	return (epsilon);
}

Fixed			&Fixed::min(Fixed &value1, Fixed &value2)
{
	return (value1 < value2 ? value1 : value2);
}

Fixed			&Fixed::max(Fixed &value1, Fixed &value2)
{
	return (value1 > value2 ? value1 : value2);
}

Fixed const		&Fixed::min(Fixed const &value1, Fixed const &value2)
{
	return (value1 < value2 ? value1 : value2);
}

Fixed const		&Fixed::max(Fixed const &value1, Fixed const &value2)
{
	return (value1 > value2 ? value1 : value2);
}

//MEMBER OPERATOR OVERLOAD DEFINITIONS//

bool			Fixed::operator<(Fixed const &right_value) const
{
	return (this->_value < right_value.getRawBits() ? true : false);
}

bool			Fixed::operator>(Fixed const &right_value) const
{
	return (this->_value > right_value.getRawBits() ? true : false);
}

bool			Fixed::operator==(Fixed const &right_value) const
{
	return (this->_value == right_value.getRawBits() ? true : false);
}

bool			Fixed::operator!=(Fixed const &right_value) const
{
	return (!(this->operator==(right_value)));
}

bool			Fixed::operator<=(Fixed const &right_value) const
{
	return ((this->operator<(right_value) | (this->operator==(right_value))));
}

bool			Fixed::operator>=(Fixed const &right_value) const
{
	return ((this->operator>(right_value) | (this->operator==(right_value))));
}

Fixed			&Fixed::operator=(Fixed const &right_value)
{
	if (this != &right_value)
		this->_value = right_value.getRawBits();
	return (*this);
}

Fixed			Fixed::operator+(Fixed const &right_value) const
{
	Fixed	sum;

	sum.setRawBits(this->_value + right_value.getRawBits());
	return (sum);
}

Fixed			Fixed::operator-(Fixed const &right_value) const
{
	Fixed	diff;

	diff.setRawBits(this->_value - right_value.getRawBits());
	return (diff);
}

Fixed			Fixed::operator*(Fixed const &right_value) const
{
	Fixed	prod;

	prod.setRawBits((((int64_t)this->_value * (int64_t)right_value.getRawBits())>>Fixed::_fractional_bits));
	return(prod);
}

Fixed			Fixed::operator/(Fixed const &right_value) const
{
	Fixed	prod;

	prod.setRawBits((((int64_t)this->_value)<<Fixed::_fractional_bits) / right_value.getRawBits());
	return(prod);
}

Fixed			&Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	old_value = *this;
	this->_value += 1;
	return (old_value);
}

Fixed			&Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed			Fixed::operator--(int)
{
	Fixed	old_value = *this;

	this->_value -= 1;
	return (old_value);
}

//FREE OPERATOR OVERLOAD DEFINITIONS//

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed_point_value)
{
	return (output << fixed_point_value.toFloat());
}

//STATIC VALUE ASSIGNMENTS//

const int Fixed::_fractional_bits = SCALE; //epsilon == 1*2^-_fractional_bits
