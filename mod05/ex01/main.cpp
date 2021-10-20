/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:11 by miki              #+#    #+#             */
/*   Updated: 2021/10/20 21:16:27 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
** When an exception is thrown, it acts like a 'goto' that skips over any
** subsequent instructions and takes you straight to the catch clauses.
**
** If you throw an exception and do not catch it, program terminates with
** uncaught exception error.
**
** Interestingly, if you try to catch the parent class before the child class,
** -Werror will cleverly complain. Good show, -Werror. ;)
*/

int	main(void)
{
	std::cout << "\tBAD FORM TEST" << std::endl;
	std::cout << "\tSign Grade Too High" << std::endl;
	try
	{
		Form		SignTooHigh("TooHigh", 0, 50);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\tExec Grade Too High" << std::endl;
	try
	{
		Form		ExecTooHigh("TooHigh", 50, 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\tSign Grade Too Low" << std::endl;
	try
	{
		Form		SignTooLow("TooLow", 151, 50);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\tExec Grade Too Low" << std::endl;
	try
	{
		Form		ExecTooLow("TooLow", 50, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\tSign Too High, Exec Too Low" << std::endl;
	try
	{
		Form		HighLow("All Over", 0, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\tSign Too Low, Exec Too High" << std::endl;
	try
	{
		Form		LowHigh("All Over", 151, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\tBoth Too Low" << std::endl;
	try
	{
		Form		LowLow("TooLow", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\tBoth Too High" << std::endl;
	try
	{
		Form		HighHigh("HighHigh", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "\tPRINT FORM TEST" << std::endl;
	{
		Form	P1("Form Access Form", 50, 25);
		std::cout << P1 << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\tINFERIOR BUREAUCRAT TEST" << std::endl;
	Bureaucrat	mariano("Mariano", 149);
	Form		P1("Loan", 50, 50);
	mariano.signForm(P1);
	std::cout << mariano << std::endl;
	std::cout << P1 << std::endl;

	std::cout << std::endl;
	std::cout << "\tSUPERIOR BUREAUCRAT TEST" << std::endl;
	Bureaucrat	carmena("Carmena", 1);
	carmena.signForm(P1);
	std::cout << carmena << std::endl;
	std::cout << P1 << std::endl;

	std::cout << std::endl;
	// // Uncaught exception test
	// Bureaucrat pablo("Pablo", 0);
	// std::cout << pablo.getGrade() << std::endl;
	
	return (0);
}
