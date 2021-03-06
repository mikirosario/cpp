/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 02:55:35 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "CLAPTRAP INSTANTIATION:" << std::endl;
	ClapTrap patricia("Patricia");
	ClapTrap kevin("Kevin");
	ClapTrap mario("Mario");
	std::cout << std::endl;
	std::cout << "CLAPTRAP ASSIGNMENT OPERATOR:" << std::endl;
	mario = patricia;
	std::cout << std::endl;
	std::cout << "CLAPTRAP FUNCTIONS:" << std::endl;
	patricia.attack("Kevin");
	kevin.takeDamage(8);
	kevin.beRepaired(20);
	std::cout << std::endl;
	std::cout << "CLAPTRAP DESTRUCTORS:" << std::endl;
	return (0);
}
