/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 12:54:56 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define NUMBER_OF_ANIMALS 10
#define HALF_NUMBER_OF_ANIMALS (NUMBER_OF_ANIMALS / 2)

int	main(void)
{
	Animal	*animals[NUMBER_OF_ANIMALS];
	int		i;

	std::cout << "FIRULAIS AND FELIX CONSTRUCTOR CALLS:" << std::endl;
	Animal* Firulais = new Dog();
	Animal* Felix = new Cat();
	std::cout << std::endl;

	std::cout << "ANIMAL ARRAY CONSTRUCTOR CALLS:" << std::endl;
	for (i = 0; i < HALF_NUMBER_OF_ANIMALS; i++)
	{
		animals[i] = new Dog();
	}
	for ( ; i < NUMBER_OF_ANIMALS; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << "IDEAS FROM ANIMAL ARRAY:" << std::endl;
	((Dog *)animals[0])->giveIdea((std::string)"I ARE DOG.");
	((Cat *)animals[NUMBER_OF_ANIMALS - 1])->giveIdea((std::string)"I ARE CAT.");
	std::cout << "First array animal says: ";
	((Dog *)animals[0])->getIdea();
	std::cout << "Last array animal says: ";
	((Cat *)animals[NUMBER_OF_ANIMALS - 1])->getIdea();
	std::cout << "Firulais says: ";
	((Dog *)Firulais)->getIdea();
	std::cout << "Felix says: ";
	((Cat *)Felix)->getIdea();
	std::cout << std::endl;

	std::cout << "DEEP COPY TEST:" << std::endl;
	std::cout << "Copying first array animal to Firulais and last array animal to Felix." << std::endl;
	*Firulais = *animals[0];
	*Felix = *animals[NUMBER_OF_ANIMALS - 1];
	std::cout << "Firulais says: ";
	((Dog *)Firulais)->getIdea();
	std::cout << "Felix says: ";
	((Cat *)Felix)->getIdea();
	// std::cout << "Copying Firulais to Felix." << std::endl;
	// *Felix = *Firulais;
	// std::cout << "Firulais says: ";
	// Firulais->getIdea();
	// std::cout << "Felix says: ";
	// Felix->getIdea();
	std::cout << std::endl;

	std::cout << "DESTRUCTOR CALLS:" << std::endl;
	for (i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
	delete Firulais;
	delete Felix;
	//system ("leaks worldfire");
	return (0);
}
