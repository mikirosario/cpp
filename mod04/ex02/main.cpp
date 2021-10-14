/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/14 15:57:05 by mrosario         ###   ########.fr       */
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
	animals[0]->giveIdea((std::string)"I ARE DOG.");
	animals[NUMBER_OF_ANIMALS - 1]->giveIdea((std::string)"I ARE CAT.");
	std::cout << "First array animal says: ";
	animals[0]->getIdea();
	std::cout << "Last array animal says: ";
	animals[NUMBER_OF_ANIMALS - 1]->getIdea();
	std::cout << "Firulais says: ";
	Firulais->getIdea();
	std::cout << "Felix says: ";
	Felix->getIdea();
	std::cout << std::endl;

	std::cout << "DEEP COPY AND DYNAMIC CAST TESTS:" << std::endl;
	std::cout << "Copying first array animal to Firulais and last array animal to Felix." << std::endl;
	*Firulais = *animals[0];
	*Felix = *animals[NUMBER_OF_ANIMALS - 1];
	std::cout << "Firulais says: ";
	Firulais->getIdea();
	Firulais->makeSound();
	std::cout << "Felix says: ";
	Felix->getIdea();
	Felix->makeSound();
	std::cout << std::endl;
	std::cout << "Copying Firulais to Felix." << std::endl;
	*Felix = *Firulais;
	std::cout << "Felix is still a Cat, but now has Firulais's ideas in its brain." << std::endl;
	std::cout << std::endl;
	std::cout << "Firulais says: ";
	Firulais->getIdea();
	Firulais->makeSound();
	std::cout << "Felix says: ";
	Felix->getIdea();
	Felix->makeSound();
	std::cout << std::endl;

	std::cout << "DESTRUCTOR CALLS:" << std::endl;
	for (i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
	delete Firulais;
	delete Felix;
	//system ("leaks worldfire");
	return (0);
}
