/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:45:41 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 02:50:51 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

#define	ASCII_TREE_FILE "trees.txt"

	ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation Form", 145, 137)
	{
	}

	ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form("Shrubbery Creation Form", 145, 137), _target(target)
	{
	}
	
	
	ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: Form(src.getName(), src.getSignatureGrade(), src.getExecutionGrade()), _target(src._target)
	{
	}

	ShrubberyCreationForm::~ShrubberyCreationForm(void)
	{
	}
	
	ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
	{
		this->_target = src._target;
		return (*this);
	}

	void	ShrubberyCreationForm::action(void) const throw (std::exception,std::string)
	{
		std::ofstream	output;
		std::ifstream	input;
		std::string		line;
		input.exceptions(std::ifstream::badbit);
		input.open(ASCII_TREE_FILE);
		if (!input.is_open())
			throw std::string(ASCII_TREE_FILE ": No Such File Exception");
		output.exceptions(std::ofstream::badbit);
		output.open(this->_target + "_shrubbery", std::ios::trunc);
		while (std::getline(input, line))
			output << line << std::endl;
		input.close();
		output.close();
	}
	