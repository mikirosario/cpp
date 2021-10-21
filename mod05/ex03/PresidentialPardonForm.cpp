/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:15:14 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 05:05:58 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "PresidentialPardonForm.hpp"
	
	PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon Form", 25, 5)
	{
	}

	PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form("Presidential Pardon Form", 25, 5), _target(target)
	{
	}
	
	PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: Form(src.getName(), src.getSignatureGrade(), src.getExecutionGrade()), _target(src._target)
	{
	}

	PresidentialPardonForm::~PresidentialPardonForm(void)
	{
	}
	
	PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
	{
		this->_target = src._target;
		return (*this);
	}

	Form const *	PresidentialPardonForm::generateForm(std::string const & target)
	{
		return (new PresidentialPardonForm(target));
	}

	void	PresidentialPardonForm::action(void) const
	{
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
	