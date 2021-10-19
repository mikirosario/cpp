/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 02:52:07 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	//Materia test
	{
		Ice ice;
		Cure cure;
		std::cout << ice.getType() << std::endl;
		std::cout << cure.getType() << std::endl;
	}
	//Character tests
	std::cout << "CHARACTER TESTS" << std::endl;
	ICharacter* Cloud = new Character("Cloud");
	std::cout << "My name is " << Cloud->getName() << "." << std::endl; //getName function
	Cloud->use(0, *Cloud); //null ref check; should ignore
	Cloud->use(8, *Cloud); //out of bounds check; should ignore

	//"Create" materias in player "inventory" -- IT'S ALL THE SAME ELECTRON!!! xD
	AMateria* tmp;
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp = src->createMateria("cure");
	Cloud->equip(tmp);
	
	//Use equipped materias against other character
	ICharacter* bob = new Character("bob");
	Cloud->use(0, *bob);
	Cloud->use(1, *bob);
	
	
	delete bob;
	delete Cloud;
	delete src;
	
	//system ("leaks ff42");
	return (0);
}
