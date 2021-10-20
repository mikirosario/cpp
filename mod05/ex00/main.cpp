/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:01:11 by miki              #+#    #+#             */
/*   Updated: 2021/10/20 18:50:36 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	std::cout << "\tGRADE TOO LOW TEST" << std::endl;
	try
	{
		Bureaucrat almeida("Almeida", 200);
		std::cerr << "\tGoes directly to catch" << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e) //Will catch child exception before parent is caught.
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "boop" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\tGRADE TOO HIGH TEST" << std::endl;
	try
	{
		Bureaucrat carmena("Carmena", 0);
		std::cerr << "\tGoes directly to catch" << std::endl;
	}
	// catch(const Bureaucrat::GradeTooHighException& e) //Will catch child exception before parent is caught.
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// catch (const Bureaucrat::GradeTooLowException & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	catch (std::exception & e) //catch via parent class
	{
		std::cout << "\tException caught via parent class!:" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\tGRADE OKAY TEST" << std::endl;
	try
	{
		Bureaucrat mediocre("Mediocre", 50);
		std::cout << "\tExecutes all try instructions:" << std::endl;
		std::cout << mediocre << std::endl;
		std::cout << "\tBureaucrat limited to try scope:" << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e) //Will catch child exception before parent is caught.
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "boop" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\tDECREMENT TEST" << std::endl; //Note, operator overloads use the Decrement() and Increment() member functions.
	try
	{
		Bureaucrat mediocre("Mediocre", 50);
		std::cout << mediocre << std::endl;
		std::cout << "\tDecrement Until Exception:" << std::endl;
		std::cout << "\tObject destroyed before exception is caught!:" << std::endl;
		for (;;)
			--mediocre;
	}
	catch(const Bureaucrat::GradeTooHighException& e) //Will catch child exception before parent is caught.
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "boop" << std::endl;
		std::cerr << e.what() << std::endl;
	}

		std::cout << "\tINCREMENT TEST" << std::endl;
	try
	{
		Bureaucrat mediocre("Mediocre", 50);
		std::cout << mediocre << std::endl;
		std::cout << "\tIncrement Until Exception:" << std::endl;
		std::cout << "\tObject destroyed before exception is caught!:" << std::endl;
		for (;;)
			--mediocre;
	}
	catch(const Bureaucrat::GradeTooHighException & e) //Will catch child exception before parent is caught.
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "boop" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	// // Uncaught exception test
	// Bureaucrat pablo("Pablo", 0);
	// std::cout << pablo.getGrade() << std::endl;
	
	return (0);
}