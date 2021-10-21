/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:08:13 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 05:40:08 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef Form const * (*form_ptr)(std::string const &);

Intern::Intern(void)
{
}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern::~Intern(void)
{
}

Intern &	Intern::operator=(Intern const & src)
{
	(void)src;
	return (*this);
}

char const * Intern::RequestedFormUnknownException::what() const throw()
{
	return ("This Form Does Not Exist, Stupid Intern!!!!");
}

Form const *	Intern::makeForm(std::string const & name, std::string const & target) const throw(Intern::RequestedFormUnknownException)
{
	std::string form[3] = {"robotomy request","shrubbery creation","presidential pardon"};
	form_ptr	form_class[3] = {&RobotomyRequestForm::generateForm,&ShrubberyCreationForm::generateForm,&PresidentialPardonForm::generateForm};

	for (size_t i = 0; i < 3; i++)
		if (form[i].compare(name) == 0)
		{
			std::cout << "Intern creates " << name << " form targeted at " << target << std::endl;
			return (form_class[i](target));
		}
	throw Intern::RequestedFormUnknownException();
}
