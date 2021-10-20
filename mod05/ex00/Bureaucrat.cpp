/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:48:04 by miki              #+#    #+#             */
/*   Updated: 2021/10/19 22:17:25 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructors and Destructor */
Bureaucrat::Bureaucrat(void) : _name("UNDEFINED"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const grade) : _name(name), _grade(grade)
{
	checkException(this->_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	checkException(this->_grade);
}

Bureaucrat::~Bureaucrat(void)
{
}

/* Local Functions */
static void			checkException(unsigned const int & grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* Class Member Functions */
//Exceptions
char const *		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

char const *		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

//Overloads
Bureaucrat &		Bureaucrat::operator=(Bureaucrat const &src)
{
	this->_name = src._name;
	this->_grade = src._grade;
	checkException(this->_grade);
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

//Methods
std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	checkException(this->_grade);
}

void				Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	checkException(this->_grade);
}

/* Global Functions */
std::ostream &		operator<<(std::ostream & output, Bureaucrat const & bureaucrat)
{
	return (output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
