/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 03:30:21 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "FRAGTRAP INHERITANCE CHAIN:" << std::endl;
	FragTrap patricia("Patricia");
	FragTrap kevin("Kevin");
	FragTrap mario("Mario");
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
	mario.highFivesGuys();
	std::cout << std::endl;
	std::cout << "FRAGTRAP DESTRUCTORS:" << std::endl;
	return (0);
}
