/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:25:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/12 00:20:21 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap patricia("Patricia");
	ClapTrap kevin("Kevin");
	ClapTrap mario("Mario");

	mario = patricia;
	patricia.attack("Kevin");
	kevin.takeDamage(8);
	kevin.beRepaired(20);
	std::cout << "- Mario, ¿cómo te llamas?" << std::endl << "- Me llamo " << mario.getName() << std::endl;
	return (0);
}
