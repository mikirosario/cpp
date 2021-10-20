/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:35:45 by miki              #+#    #+#             */
/*   Updated: 2021/10/19 22:09:44 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <ostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string		_name;
		unsigned int	_grade;
		Bureaucrat(void); //Shouldn't be undefined, right?
	public:
		Bureaucrat(std::string const &name, unsigned int const grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat &		operator=(Bureaucrat const &src);
		unsigned int		operator++(void); //prefix
		unsigned int		operator++(int); //postfix
		unsigned int		operator--(void);
		unsigned int		operator--(int);
		void				incrementGrade(void);
		void				decrementGrade(void);
		std::string const & getName(void) const;
		unsigned int		getGrade(void) const; //variable copy, so you can do chained arithmetic with it?
		class GradeTooHighException : public std::exception
		{
			public:
				char const * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				char const * what() const throw();
		};
};

std::ostream &			operator<<(std::ostream & output, Bureaucrat const & bureaucrat);

#endif