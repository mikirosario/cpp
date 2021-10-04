/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:56:20 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 00:32:01 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <exception>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zptr;

	try
	{
		zptr = new Zombie[N];
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception in zombieHorde function: " << e.what() << std::endl;
		return (NULL);
	}
	for (--N; N >= 0; N--)
	{
		zptr[N].setName(name);
	}
	return (zptr);
}