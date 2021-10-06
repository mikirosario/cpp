/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:51:19 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 21:01:33 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zptr;

	try
	{
		zptr = new Zombie(name);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception in newZombie function: " << e.what() << '\n';
		return (NULL);
	}

	return(zptr);
}
