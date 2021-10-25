/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 01:38:53 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/25 09:59:01 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include<iostream>
#include<vector>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_array;
		static void	copy_array(std::vector<int> * dest, std::vector<int> const * src, unsigned int & copied);
		class SpanFullException : public std::exception
		{
			public:
				char const *	what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				char const *	what() const throw();
		};
	public:
		Span(void);
		Span(unsigned int const & n);
		Span(Span const & src);
		~Span(void);
		Span &			operator=(Span const & src);
		void			addNumber(int const & n) throw(Span::SpanFullException);
		void			addNumber(std::vector<int>::const_iterator const & begin, std::vector<int>::const_iterator const & end) throw(Span::SpanFullException);
		void			randomFill(void);
		unsigned int	shortestSpan(void) const throw(Span::NoSpanException);
		unsigned int	longestSpan(void) const throw(Span::NoSpanException);
		void			toFile(std::string const & filename) const;
};

#endif
