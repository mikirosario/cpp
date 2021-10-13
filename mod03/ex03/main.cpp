/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 17:00:25 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "DIAMONDTRAP INHERITANCE CHAIN:" << std::endl;
	DiamondTrap patricia("Patricia");
	DiamondTrap kevin("Kevin");
	DiamondTrap mario("Mario");
	ScavTrap *virtual_destructor_test = new DiamondTrap("V. Destructor");
	std::cout << std::endl;
	std::cout << "DERIVED ASSIGNMENT OPERATOR:" << std::endl;
	mario = patricia;
	std::cout << std::endl;
	std::cout << "DERIVED ATTACK:" << std::endl;
	patricia.attack("Kevin");
	std::cout << std::endl;
	std::cout << "BASE DAMAGE AND REPAIR:" << std::endl;
	kevin.takeDamage(8);
	kevin.beRepaired(20);
	std::cout << std::endl;
	std::cout << "DERIVED HIGH FIVES:" << std::endl;
	mario.highFivesGuys();
	std::cout << std::endl;
	std::cout << "DERIVED GUARD GATE:" << std::endl;
	mario.guardGate();;
	std::cout << std::endl;
	std::cout << "WHOAMI:" << std::endl;
	patricia.whoAmI();
	kevin.whoAmI();
	mario.whoAmI();
	std::cout << std::endl;
	std::cout << "DIAMONDTRAP DESTRUCTORS:" << std::endl;
	delete virtual_destructor_test;
	return (0);
}
