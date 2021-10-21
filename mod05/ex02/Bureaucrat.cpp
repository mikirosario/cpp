/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:48:04 by miki              #+#    #+#             */
/*   Updated: 2021/10/21 17:20:17 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
** Some study notes about throw:
**
** Throw copy-initializes the class passed as parameter. In this case, the class
** is auto-instantiated by the default c++ constructor, as it has no constructor
** override. The two custom exception classes are GradeTooHighException and
** GradeTooLowException.
**
** Since GradeTooHighException and GradeTooLowException inherit from
** std::exception, that class is likewise instantiated as the parent object.
**
** Our two child classes of the std::exception object contain a what() override,
** which will override the default what() member function in std::exception.
**
** With the exception object instantiated, we return to the next catch block that
** can receive that object as a parameter (that is, one that accepts an instance
** of the exception object, or a reference to it, as an argument).
**
** In this case, that would be any object that could receive a std::exception,
** or a GradeTooHighException / GradeTooLowException (which are subclasses of
** std::exception).
**
** The std::exception::what() function is virtual, so polymorphism applies.
** Thus, any reference to what(), even a reference to the parent function's
** what() (std::exception e.what()) will use a virtual table to divert to the
** child function's what() override and return the desired message.
*/

/* Local Functions */
static void			checkException(unsigned const int & grade) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(); //Throw exception and return to next catch block
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* Constructors and Destructor */
Bureaucrat::Bureaucrat(void) : _name("UNDEFINED"), _grade(1)
{
	std::cout << GRN << "Constructed Bureaucrat" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const grade) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException)
: _name(name), _grade(grade)
{
	checkException(this->_grade);
	std::cout << GRN << "Constructed Bureaucrat" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << GRN << "Constructed Bureaucrat" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << GRN << "Destroyed Bureaucrat" << RESET << std::endl;
}

/* Class Member Functions */
//Exceptions
char const *		Bureaucrat::GradeTooLowException::what() const throw() //override what function from exception class
{
	return (RED"Grade Too Low Exception"RESET); //what function returns a const char * to a string. now it returns this message.
}

char const *		Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED"Grade Too High Exception"RESET);
}

//Overloads
Bureaucrat &		Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_grade = src._grade;
	return (*this);
}

unsigned int		Bureaucrat::operator++(void)
{
	this->incrementGrade();
	return (this->_grade);
}

unsigned int		Bureaucrat::operator++(int)
{
	unsigned int	grade = this->_grade;

	this->incrementGrade();
	return (grade);
}

unsigned int		Bureaucrat::operator--(void)
{
	this->decrementGrade();
	return (this->_grade);
}

unsigned int		Bureaucrat::operator--(int)
{
	unsigned int	grade = this->_grade;

	this->decrementGrade();
	return (grade);
}

//Other Member Functions
std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade(void) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException)
{
	checkException(this->_grade - 1);
	this->_grade -= 1;
}

void				Bureaucrat::decrementGrade(void) throw(Bureaucrat::GradeTooHighException,Bureaucrat::GradeTooLowException)
{
	checkException(this->_grade + 1);
	this->_grade += 1;
}

void				Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " due to the following reason: " << std::endl;
		std::cerr << e.what() << std::endl;
	}		
}

void				Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << this->_name << " cannot execute " << form.getName() << " due to the following reason: " << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

/* Global Functions */
std::ostream &		operator<<(std::ostream & output, Bureaucrat const & bureaucrat)
{
	return (output << GRN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET);
}
