/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:11 by miki              #+#    #+#             */
/*   Updated: 2021/10/21 02:53:58 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "LEHENDAKARI ACCESS LEVEL" << std::endl;
	try
	{
		Bureaucrat				lehendakari("Zafod Beeblebrox", 1);
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robotomy("Marvin");
		PresidentialPardonForm	pardon("Code Copycat");
		
		lehendakari.signForm(shrub);
		lehendakari.executeForm(shrub);
		lehendakari.signForm(robotomy);
		lehendakari.executeForm(robotomy);
		lehendakari.signForm(pardon);
		lehendakari.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "M. RAJOY ACCESS LEVEL" << std::endl;
	try
	{
		Bureaucrat				functionary("M. Rajoy", 50);
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robotomy("Marvin");
		PresidentialPardonForm	pardon("Code Copycat");
		
		functionary.signForm(shrub);
		functionary.executeForm(shrub);
		functionary.signForm(robotomy);
		functionary.executeForm(robotomy);
		functionary.signForm(pardon);
		functionary.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "DON NADIE ACCESS LEVEL" << std::endl;
	try
	{
		Bureaucrat				nobody("Don Nadie", 150);
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robotomy("Marvin");
		PresidentialPardonForm	pardon("Code Copycat");
		
		nobody.signForm(shrub);
		nobody.executeForm(shrub);
		nobody.signForm(robotomy);
		nobody.executeForm(robotomy);
		nobody.signForm(pardon);
		nobody.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
