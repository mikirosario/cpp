/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:01:15 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 02:10:10 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

//#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <exception>

#define RED "\e[1;31m"
#define GRN "\e[1;32m"
#define RESET "\e[0m"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		uint const			_sign_grade;
		uint const			_exec_grade;
		Form &				operator=(Form const & src);
	protected:
		virtual void		action(void) const = 0;
	public:
		Form(void);
		Form(std::string const & name, uint const & sign_grade, uint const & exec_grade);
		Form(Form const & src);
		virtual ~Form(void);
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
		class FormNotSignedException : public std::exception
		{
		public:
				char const * what() const throw();
		};
		std::string const &	getName(void) const;
		bool const & 		getSignature(void) const;
		uint				getSignatureGrade(void) const;
		uint				getExecutionGrade(void) const;
		void				beSigned(Bureaucrat const & bureaucrat) throw (Form::GradeTooLowException);
		void				execute(Bureaucrat const & executor) const throw (Form::GradeTooLowException,Form::FormNotSignedException);
};

std::ostream &	operator<<(std::ostream & output, Form const & form);

#endif
