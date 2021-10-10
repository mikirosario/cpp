/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:53:50 by miki              #+#    #+#             */
/*   Updated: 2021/10/11 01:38:46 by miki             ###   ########.fr       */
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

/*
** WHY!? You may ask. Because the 42 exercise obliged us to create a Point class
** with two Fixed const integers, x and y, AND to create an assignation overload
** for it.
**
** So far I've seen people resolve this seeming contradiction in two ways: make
** the assignation operator do nothing (mean!), or forego the const specifier on
** the Fixed integers (non-compliant). Inspired by Captain Kirk's philosophy
** regarding no-win scenarios, I've decided on a third approach: write the
** assignation in assembly code. xD Now the Fixed integers can be const, and I
** can overwrite them anyway. Woo-hoo!
*/

static	void kobayashi_maru(Fixed const *this_var, Fixed const *that_var)
{
		int		type_size = sizeof(Fixed);

		__asm__ ("xorq %%rcx,%%rcx;"	//zero rcx, to use as counter
		"xorq %%rax,%%rax;"				//zero rax, to use to store bytes as they are transferred
		"loop: ;"						//loop begins
		"cmp %2,%%ecx;"					//compare counter to type_size
		"je end;"						//if equal, jump to end
		"movb (%1),%%al;"				//copy byte from *that_var to al
		"movb %%al,(%0);"				//copy byte from al to *this_var
		"inc %1;"						//increment this_var ptr
		"inc %0;"						//increment that_var ptr
		"inc %%ecx;"					//increment counter
		"jmp loop;"						//return to loop beginning
		"end: ;"						//end loop
	:
	: "D" (this_var), "S" (that_var), "d" (type_size)
	: "%rcx", "%rax");
}

Point	&Point::operator=(Point const &point)
{
	kobayashi_maru(&this->x, &point.x);
	kobayashi_maru(&this->y, &point.y);
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
