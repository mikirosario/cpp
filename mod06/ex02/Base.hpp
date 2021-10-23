/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:18:33 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 03:32:32 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base *	generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
