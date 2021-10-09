/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:19:58 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/09 13:49:10 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//int == 4 bytes == 32 bits
//fractional bits 8
//integer bits 24 (23)
//sign bit 1

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(int const int_value)
{
	this->_value = int_value << this->_fractional_bits;
}

Fixed::Fixed(float const float_value)
{
	this->_value = (int)roundf(float_value * (float)(1 << this->_fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fractional_bits);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed	&Fixed::operator=(Fixed const &right_value)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &right_value)
		this->_value = right_value.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed_point_value)
{
	return (output << fixed_point_value.toFloat());
}