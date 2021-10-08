/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:19:58 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/08 20:27:48 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::toInt(void)
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
