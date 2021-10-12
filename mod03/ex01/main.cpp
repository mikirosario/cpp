/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 03:14:41 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "SCAVTRAP INHERITANCE CHAIN:" << std::endl;
	ScavTrap patricia("Patricia");
	ScavTrap kevin("Kevin");
	ScavTrap mario("Mario");
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
	std::cout << "DERIVED GUARD GATE:" << std::endl;
	mario.guardGate();
	std::cout << std::endl;
	std::cout << "SCAVTRAP DESTRUCTORS:" << std::endl;
	return (0);
}
