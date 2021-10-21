/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:35:45 by miki              #+#    #+#             */
/*   Updated: 2021/10/21 02:20:20 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <ostream>
#include <exception>

#define RED "\e[1;31m"
#define GRN "\e[1;32m"
#define RESET "\e[0m"

class Form;

class Bureaucrat
{
	private:
		std::string		_name;
		unsigned int	_grade;
		Bureaucrat(void); //Shouldn't be undefined, right?
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				char const * what() const throw(); //override what() function from exception class
		};
		class GradeTooLowException : public std::exception
		{
			public:
				char const * what() const throw();
		};
		Bureaucrat(std::string const &name, unsigned int const grade) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat &		operator=(Bureaucrat const &src);
		unsigned int		operator++(void); //prefix
		unsigned int		operator++(int); //postfix
		unsigned int		operator--(void);
		unsigned int		operator--(int);
		void				incrementGrade(void) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException);
		void				decrementGrade(void) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException);
		std::string const & getName(void) const;
		unsigned int		getGrade(void) const; //variable copy, so you can do chained arithmetic with it
		void				signForm(Form & form) const;
		void				executeForm(Form const & form);
};

std::ostream &			operator<<(std::ostream & output, Bureaucrat const & bureaucrat);

#endif
