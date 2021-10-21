/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:12:45 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 02:51:33 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void			checkException(unsigned const int & grade) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(); //Throw exception and return to next catch block
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

//Constructors and Destructor
Form::Form(void) : _name("UNDEFINED"), _is_signed(false), _sign_grade(1),
_exec_grade(1)
{
	std::cout << GRN << "Constructed Form" << RESET << std::endl;
}

Form::Form(std::string const & name, uint const & sign_grade, uint const & exec_grade) :
_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	checkException(this->_sign_grade);
	checkException(this->_exec_grade);
	std::cout << GRN << "Constructed Form" << RESET << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _is_signed(src._is_signed),
_sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	checkException(this->_sign_grade);
	checkException(this->_exec_grade);
	std::cout << GRN << "Constructed Form" << RESET << std::endl;
}

Form::~Form(void)
{
	std::cout << GRN << "Destroyed Form" << RESET << std::endl;
}

//Member overloads
Form &				Form::operator=(Form const & src) //const values, makes no sense
{
	(void)src;
	return (*this);
}

//Member functions

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool const &		Form::getSignature(void) const
{
	return (this->_is_signed);
}

uint				Form::getSignatureGrade(void) const
{
	return (this->_sign_grade);
}

uint				Form::getExecutionGrade(void) const
{
	return (this->_exec_grade);
}

void				Form::beSigned(Bureaucrat const & bureaucrat) throw(Form::GradeTooLowException)
{
	uint const & bureaucrat_grade = bureaucrat.getGrade();

	if (bureaucrat_grade > this->_sign_grade)
		throw Form::GradeTooLowException();
	else
		this->_is_signed = true;
}

void				Form::execute(Bureaucrat const & executor) const throw (Form::GradeTooLowException,Form::FormNotSignedException)
{
	uint const & bureaucrat_grade = executor.getGrade();
	if (!this->_is_signed)
		throw Form::FormNotSignedException();
	else if (bureaucrat_grade > this->_exec_grade)
		throw Form::GradeTooLowException();
	else
	{
		try
		{
			this->action(); //open/close file may fail for Shrubbery action :p
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(const std::string & s)
		{
			std::cerr << s << std::endl;
		}
	}
}

//Exceptions
char const *		Form::GradeTooHighException::what(void) const throw()
{
	return (RED"Grade Too High Exception"RESET);
}

char const *		Form::GradeTooLowException::what(void) const throw()
{
	return (RED"Grade Too Low Exception"RESET);
}

char const *		Form::FormNotSignedException::what(void) const throw()
{
	return (RED"Form Not Signed Exception"RESET);
}

//Global functions
std::ostream &	operator<<(std::ostream & output, Form const & form)
{
	return (output << form.getName()
	<< " with a minimum signature grade of " << form.getSignatureGrade()
	<< " and a minimum execution grade of " << form.getExecutionGrade()
	<< " is " << (form.getSignature() ? "signed." : "not signed."));
}
