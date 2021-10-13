/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 17:41:12 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// std::cout << "My tests:" << std::endl;
	// std::string tmp = "test";
	// Animal stem_animal1(tmp);
	// Animal stem_animal2;
	// Dog	Firulais;
	// stem_animal2 = Firulais;
	// stem_animal1.makeSound();
	// Firulais.makeSound();
	// stem_animal2.makeSound();
	// std::cout << std::endl <<std::endl;
	
	std::cout << "42 TESTS:" << std::endl;
	std::cout << std::endl;
	std::cout << "Constructors:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Dog *f = new Dog();
	std::cout << std::endl;
	std::cout << "Get Type:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << "Assignation test:" << std::endl;
	*f = *((Dog *)j);
	std::cout << std::endl;
	std::cout << "Make Sound:" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	f->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "WrongAnimal Constructors:" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	std::cout << std::endl;
	std::cout << "WrongAnimal Get Type:" << std::endl;
	std::cout << wrong_i->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << "WrongAnimal Make Sound:" << std::endl;
	wrong_i->makeSound(); //will output the animal sound!
	wrong_meta->makeSound();
	std::cout << std::endl;
	std::cout << "Destructors:" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete f;
	delete wrong_meta;
	delete wrong_i;
	return (0);
}
