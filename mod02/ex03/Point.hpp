/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:50:57 by miki              #+#    #+#             */
/*   Updated: 2021/10/10 21:22:39 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point(void);
		Point(Point &point);
		Point(float const a, float const b);
		~Point(void);
		Point		&operator=(Point const &point);
		//Point		&operator=(Point &point);
		Fixed		getX(void) const;
		Fixed 		getY(void) const;
};

#endif