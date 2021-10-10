/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:53:50 by miki              #+#    #+#             */
/*   Updated: 2021/10/10 08:16:34 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(Point &point) : x(point.x), y(point.y)
{
}

Point::Point(float const a, float const b) : x(a), y(b)
{
}

Point::~Point(void)
{
}

Point	&Point::operator=(Point const &point)
{
	(Fixed)this->x = point.x;
	(Fixed)this->y = point.y;
	return (*this);
}

Fixed 	Point::getX(void) const
{
	return (this->x);
}
Fixed	Point::getY(void) const
{
	return (this->y);
}
