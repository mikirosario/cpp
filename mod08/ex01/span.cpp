/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 01:51:49 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/25 06:02:36 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>

#define RED "\e[1;31m"
#define GRN "\e[1;32m"
#define RESET "\e[0m"

Span::Span(void) : _size(0)
{}

Span::Span(unsigned int const & n) : _size(n)
{
}

Span::Span(Span const & src) : _size(src._size)
{
	std::copy(src._array.begin(), src._array.end(), this->_array.begin());
}

Span::~Span(void)
{
}

Span &	Span::operator=(Span const & src)
{
	this->_array.clear();
	this->_size = src._size;
	std::copy(src._array.begin(), src._array.end(), this->_array.begin());
	return (*this);
}

char const *	Span::SpanFullException::what(void) const throw ()
{
	return (RED"Span Full Exception"RESET);
}

char const *	Span::NoSpanException::what(void) const throw ()
{
	return (RED"No Span Exception"RESET);
}

void	Span::addNumber(int const & n) throw (Span::SpanFullException)
{
	if (this->_array.size() < this->_size)
		this->_array.push_back(n);
	else
		throw (Span::SpanFullException());
}

unsigned int	Span::longestSpan(void) const throw (Span::NoSpanException)
{
	if (this->_array.size() < 2)
		throw (Span::NoSpanException());
	else
	{
		std::vector<int>::const_iterator max;
		std::vector<int>::const_iterator min;

		max = std::max_element(this->_array.begin(), this->_array.end());
		min = std::min_element(this->_array.begin(), this->_array.end());
		return (std::abs((*max - *min)));
	}
}

unsigned int	Span::shortestSpan(void) const throw (Span::NoSpanException)
{
	if (this->_array.size() < 2)
		throw (Span::NoSpanException());
	else
	{
		std::vector<int>	sort_copy(this->_array.size());
		unsigned int		lowest_diff = UINT_MAX;
		unsigned int		diff;

		std::partial_sort_copy(this->_array.begin(), this->_array.end(),
		sort_copy.begin(), sort_copy.end());
		for (std::vector<int>::const_iterator it = sort_copy.begin(), end = sort_copy.end() - 1;
		it != end; ++it)
		{
			diff = (*(it + 1) - *it);
			if (diff < lowest_diff)
				lowest_diff = diff;
		}
		return (lowest_diff);
	}
}
