/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/19 04:56:54 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#ifdef __APPLE__
	# define LEAK_CHECK system("leaks ff42")
#else
	# define LEAK_CHECK std::cout << "Just use Valgrind ;)" << std::endl
#endif

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	IMateriaSource* assign_test = new MateriaSource();
	//Materia tests
	std::cout << "MATERIA TESTS" << std::endl;

	std::cout << "Learn Materia Overload Test (calls after 4th should be ignored):" << std::endl;
	AMateria *legendary_fifth_materia; //"Note, to avoid a memory leak I save the reference to the 5th one ;)
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria((legendary_fifth_materia = new Cure()));
	delete legendary_fifth_materia;
	std::cout << std::endl;

	std::cout << "Materia Source Assignment Test:" << std::endl;
	*assign_test = *src;
	Character Pepe("Pepe");
	Character Pili("Pili");
	//src materias assigned to assign_test, so now assign_test can be used to equip characters
	Pepe.equip(assign_test->createMateria("cure"));
	//Pepe accesses "cure" via assign_test, which was copied from src, and can now use it on Pili
	Pepe.use(0, Pili);
	std::cout << std::endl;

	std::cout << "Name Call by Direct References:" << std::endl;
	Ice ice;
	Cure cure;
	std::cout << ice.getType() << std::endl;
	std::cout << cure.getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Name Call by Indirect References:" << std::endl;
	AMateria *icep = new Ice();
	AMateria *curep = new Cure();
	std::cout << icep->getType() << std::endl; //getType is inherited, and _type is defined in parent, so no problems
	std::cout << curep->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Assignment Overload Between Unlike Materias (should be ignored):" << std::endl;
	*icep = *curep; //should be ignored; would need to be virtualized for type-appropriate assignments,
					//if there were any data to copy between like types here :)
	std::cout << icep->getType() << std::endl;
	std::cout << curep->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Use Function (Direct and Indirect References):" << std::endl;
	Character Aeris("Aeris");
	ice.use(Aeris); //You can pass a direct reference to derived class as base class!
	icep->use(Aeris);
	delete icep;
	delete curep;
	std::cout << std::endl;

	//Character tests
	std::cout << "CHARACTER TESTS" << std::endl;
	ICharacter* Cloud = new Character("Cloud");
	ICharacter* Sephiroth = new Character("Sephiroth");

	std::cout << "Name Call by Indirect Reference:" << std::endl;
	std::cout << "My name is " << Cloud->getName() << "." << std::endl; //getName function is true virtual, so every child MUST define their own
	std::cout << std::endl;

	std::cout << "Use Function Null Ref Checks (nothing should happen):" << std::endl;
	Cloud->use(0, *Cloud); //null ref check; should ignore
	Cloud->use(8, *Cloud); //out of bounds check; should ignore
	std::cout << std::endl;

	std::cout << "Equip and Use Tests:" << std::endl;
	//"Create" materias in player "inventory" -- IT'S ALL THE SAME ELECTRON!!! xD
	AMateria* tmp;
	tmp = src->createMateria("ice");
	Cloud->equip(tmp);
	tmp = src->createMateria("cure");
	Cloud->equip(tmp);
	//Use equipped materias against another character
	Cloud->use(0, *Sephiroth);
	Cloud->use(1, *Sephiroth);
	std::cout << std::endl;

	std::cout << "Unequip and Use Tests (use calls should now be ignored):" << std::endl;
	Cloud->unequip(0); //references to materia instances removed from inventory; pointers nulled
	Cloud->unequip(1);
	Cloud->use(0, *Sephiroth); //null refs ignored
	Cloud->use(1, *Sephiroth);
	std::cout << std::endl;

	std::cout << "Character Inventory Overload Test (calls after 4th should be ignored):" << std::endl;
	Cloud->equip(src->createMateria("cure"));
	Cloud->equip(src->createMateria("cure"));
	Cloud->equip(src->createMateria("cure"));
	Cloud->equip(src->createMateria("cure"));
	Cloud->equip(src->createMateria("ice"));
	for (int i = 0; i < 4; i++)
		Cloud->use(i, *Sephiroth);
	std::cout << std::endl;

	std::cout << "And now, for the moment we've all been waiting for... SEPHIROTH = CLOUD!!!!:" << std::endl;
	*Sephiroth = *Cloud;  //Sephiroth should now have all of Cloud's materia references, and believe he is Cloud.
	std::cout << "Sephiroth says: 'My name is " << Sephiroth->getName() << "'. :O" << std::endl;
	for (int i = 0; i < 4; i++)
		Sephiroth->use(i, *Cloud);
	std::cout << std::endl;

	std::cout << "LEAK CHECK" << std::endl;
	delete Sephiroth;
	delete Cloud;
	delete src;
	delete assign_test;	
	LEAK_CHECK;
	return (0);
}
