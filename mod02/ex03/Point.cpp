/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:53:50 by miki              #+#    #+#             */
/*   Updated: 2021/10/11 20:19:09 by mrosario         ###   ########.fr       */
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

// /*
// ** WHY!? You may ask. Because the 42 exercise obliged us to create a Point class
// ** with two Fixed const integers, x and y, AND to create an assignation overload
// ** for it.
// **
// ** So far I've seen people resolve this seeming contradiction in two ways: make
// ** the assignation operator do nothing (mean!), or forego the const specifier on
// ** the Fixed integers (non-compliant). Inspired by Captain Kirk's philosophy
// ** regarding no-win scenarios, I've decided on a third approach: write the
// ** assignation in assembly code. xD Now the Fixed integers can be const, and I
// ** can overwrite them anyway. Woo-hoo!
// */

// static	void kobayashi_maru(Fixed const *this_var, Fixed const *that_var)
// {
// 		int		type_size = sizeof(Fixed);

// 		__asm__ ("xorq %%rcx,%%rcx;"	//zero rcx, to use as counter
// 		"xorq %%rax,%%rax;"				//zero rax, to use to store bytes as they are transferred
// 		"loop: ;"						//loop begins
// 		"cmp %2,%%ecx;"					//compare counter to type_size
// 		"je end;"						//if equal, jump to end
// 		"movb (%1),%%al;"				//copy byte from *that_var to al
// 		"movb %%al,(%0);"				//copy byte from al to *this_var
// 		"inc %1;"						//increment this_var ptr
// 		"inc %0;"						//increment that_var ptr
// 		"inc %%ecx;"					//increment counter
// 		"jmp loop;"						//return to loop beginning
// 		"end: ;"						//end loop
// 	:
// 	: "D" (this_var), "S" (that_var), "d" (type_size)
// 	: "%rcx", "%rax");
// }

/*
** The 42 exercise obliged us to create a Point class with two Fixed const
** integers, x and y, AND to create an assignation overload for it. This should
** not be possible, because you cannot change a const after it is instantiated,
** that's why it's a const.
**
** First I tried casting the variable directly to Fixed, but in this module I
** quickly discovered that casting a variable creates a COPY, rather than a new
** interpretation of an existing variable. Which makes perfect sense, of course.
** I just never gave it any thought. This is why the compiler understands me
** when I cast my floats to (Fixed), even though I have no explicit cast
** instructions - it creates a new Fixed instance with the float, so it just
** calls my constructor that accepts a float reference. Therefore, when casting
** the Fixed const variable to Fixed, it created a copy of the variable and did
** the assignment to the copy, rather than to the Fixed variable pointed to by
** 'this'.
**
** So far I've seen people resolve this seeming contradiction in two ways: make
** the assignation operator do nothing (mean!), or forego the const specifier on
** the Fixed integers (non-compliant). Inspired by Captain Kirk's philosophy
** regarding no-win scenarios, I first decided on a third approach: write the
** assignation in assembly code. xD Now the Fixed integers can be const, and I
** can overwrite them anyway. Woo-hoo!
**
** But then I asked rnavarre if he could think of any other approaches, and he
** suggested trying to cast a pointer to the const variable instead of the
** variable directly. So I tried it and it worked!
**
** My understanding of what is happening is: we create a Fixed const pointer to
** a Fixed const variable, which is legit. C does not allow you to create a
** non-const pointer to a const variable normally, it won't compile, because in
** C const is part of the type, and pointer types must match the type of the
** variable they point to. However, if I then cast the pointer I already created
** it creates a new pointer with the address of the old pointer copied into it.
** So if I cast it to Fixed *, I now have a Fixed pointer to a variable, even
** though I declared the variable to be const. Does the compiler notice? No!
** So using the new pointers, I can now write to variables I declared const.
**
** I almost feel bad for cheating the compiler like this. xD But I've gotta
** follow the subject. Personally I think my assembly solution is more honest,
** because I'm blatantly admitting that I'm ignoring the C type and doing stuff
** behind the compiler's back. I'm doing the exact same thing with the pointer
** cast, only obfuscated to seem legitimate.
**
** But it does raise less eyebrows this way. xD Thanks, rnavarre. xD
*/

Point	&Point::operator=(Point const &point)
{
	Fixed const *thisX = &this->x;
	Fixed const *thisY = &this->y;
	// kobayashi_maru(&this->x, &point.x);
	// kobayashi_maru(&this->y, &point.y);

	*((Fixed *)thisX) = point.x;
	*((Fixed *)thisY) = point.y;
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
