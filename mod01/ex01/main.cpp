/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:08:39 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:37:10 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include "Zombie.hpp"

/*
** //HEAP ZOMBIES\\
** The zombies in the first for loop are pushed to Heap, because memory for them
** is reserved by the newZombie function (which calls 'new') during run time.
** This memory is independent of the function that reserved it, so I can
** continue accessing it and using it by passing its reference out of that
** function's scope, even after the program returns from the function and frees
** up all the memory being used by the function (the function's memory will be
** on the Stack).
**
** They are destroyed when I call delete on them, which should be when they are
** no longer necessary. The OS should also free all referenced memory upon
** program termination, however, if I didn't call delete on them before
** reassigning the pointer, the reference to the memory I reserved would be
** lost, and that would cause a memory leak.
**
** //STACK ZOMBIES\\
** The zombies in the second for loop are pushed to Stack, because they are
** explicity declared at compile time as part of the memory occupied by the
** randomChump function and never leave the scope of that function. Their
** lifespan is therefore equal to the lifespan of the function they are part of,
** and when the function is out of scope and its Stack memory is freed, the
** zombie, as part of the function memory, will be freed with the rest of it.
**
** Thus, they are destroyed whenever the program returns from the randomChump
** function. References to them can be passed, but will only be relevant so long
** as the program remains within the function's scope (hasn't returned from the
** function). Otherwise, to save any associated data beyond the function's scope
** the data would need to be copied, either to Heap or to another,
** adequately-sized part of the Stack pertaining to a function that is still in
** scope.
*/

int	main(int argc, char **argv)
{
	int			zombie_number;
	std::string	zombie_name;
	Zombie		*zombie_horde = NULL;

	if (argc != 3 || (zombie_number = std::atoi(argv[1])) < 1)
	{
		std::cerr << "Specify zombie number and name, i.e.: [moarbrainz 4 lola]" << std::endl;
		return (1);
	}
	zombie_name = argv[2];

	zombie_horde = zombieHorde(zombie_number, zombie_name);
	if (zombie_horde)
	{
		for (int i = 0; i < zombie_number; i++)
			zombie_horde[i].announce();
		delete[] (zombie_horde);
	}
	return (0);
}
