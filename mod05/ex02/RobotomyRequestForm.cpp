/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:42:31 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 01:48:28 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <time.h>
#include "RobotomyRequestForm.hpp"

	RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request Form", 72, 45)
	{
	}
	
	RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form("Robotomy Request Form", 72, 45), _target(target)
	{
	}

	RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: Form(src.getName(), src.getSignatureGrade(), src.getExecutionGrade()), _target(src._target)
	{
	}

	RobotomyRequestForm::~RobotomyRequestForm(void)
	{
	}
	
	RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
	{
		this->_target = src._target;
		return (*this);
	}

	void	RobotomyRequestForm::action(void) const
	{
		std::cout << "Brrrrrrr bzzzzz bzzzz brrrrrrr " << std::endl;
		srand(time(NULL));
		std::cout << this->_target << ((rand() % 2) == 0 ? " robotomized successfully." : " robotomy failed.") << std::endl;
	}
	