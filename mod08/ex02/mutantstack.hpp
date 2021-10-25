/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:12:52 by miki              #+#    #+#             */
/*   Updated: 2021/10/25 20:28:27 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <algorithm>

//default container type is double-ended queue
template<typename T, typename ContType = std::deque<T>>
class MutantStack : public std::stack<T,ContType>
{
	private:
		MutantStack(T());
	public:
		//c++98 style default instantiation to empty T()
		explicit MutantStack(ContType const & cont = ContType()) : std::stack<T,ContType>(cont)
		{}
		MutantStack(MutantStack const & src) : std::stack<T,ContType>(src.c)
		{}
		~MutantStack(void)
		{}
		MutantStack &	operator=(MutantStack const & src)
		{
			this->c = src.c;
			return (*this);
		}
		typedef typename ContType::iterator iterator;
		typedef typename ContType::const_iterator const_iterator;
		typename ContType::iterator	begin(void)
		{
			return (this->c.begin());
		}
		typename ContType::iterator	end(void)
		{
			return (this->c.end());
		}
		typename ContType::iterator	rbegin(void)
		{
			return (this->c.rbegin());
		}
		typename ContType::iterator	rend(void)
		{
			return (this->c.rend());
		}
		typename ContType::const_iterator	begin(void) const
		{
			return (this->c.begin());
		}
		typename ContType::const_iterator	end(void) const
		{
			return (this->c.end());
		}
		typename ContType::const_iterator	rbegin(void) const
		{
			return (this->c.rbegin());
		}
		typename ContType::const_iterator	rend(void) const
		{
			return (this->c.rend());
		}
};

#endif
