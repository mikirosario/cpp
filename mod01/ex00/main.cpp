/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:08:39 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/07 02:49:48 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include "Zombie.hpp"

/*
** This parser is REVENGE for 2 years of Norminette! No explanation. I'll let it
** speak for itself! xD
*/

size_t	get_zombie_names(std::vector<std::string> *zombie_names, char **argv)
{
	size_t	name_len = 0;
	size_t	number_of_zombies = 0;

	for (++argv ; *argv; argv++)
	{
		for (char *name = *argv; *name; name += name_len, name_len = 0)
		{
			for ( ; std::isspace(*name) ; name++)
			{
			}
			for ( ; name[name_len] && !std::isspace(name[name_len]) ; name_len++)
			{
			}
			std::string	name_str(name, name_len);
			zombie_names->push_back(name_str);
			number_of_zombies++;
			for ( ; std::isspace(name[name_len]) ; name_len++)
			{
			}
		}		
	}
	return (number_of_zombies);
}

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
	std::vector<std::string>					zombie_names;
	Zombie										*zombie_ptr;
	size_t										number_of_zombies;
	size_t										i = 0;
	
	if (argc < 2)
	{
		std::cerr << "Pass in zombie names as arguments like this: [./brainz Pepe Paco Pili Lulu]" << std::endl;
		return (1);
	}
	number_of_zombies = get_zombie_names(&zombie_names, argv);
	//HEAP ZOMBIES
	for ( ; i < number_of_zombies / 2; i++)
	{
		zombie_ptr = newZombie(zombie_names[i]);
		if (zombie_ptr)
		{
			zombie_ptr->announce();
			delete(zombie_ptr);
		}
	}
	//STACK ZOMBIES
	for ( ; i < number_of_zombies; i++)
		randomChump(zombie_names[i]);
	
	// //DEBUG CODE Name printer
	// for (std::vector<std::string>::const_iterator it = zombie_names.begin(); it < zombie_names.end(); it++)
	// 	std::cout << *it << std::endl;
	// //DEBUG CODE
	return (0);
}
