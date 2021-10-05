/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:11:16 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/05 21:43:02 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
** HumanA needs to store his weapon as a reference essentially because he can't
** ever have no weapon, and since references cannot be NULL this prevents
** instantiation of a HumanA without a weapon.
**
** HumanB needs to store his weapon as a pointer essentially because it is
** possible for him to not have a weapon, so his weapon may be NULL, which is
** only possible with pointers.
**
** There is really no other reason to prefer one over the other. As you can see,
** it's perfectly possible to get the address of a referenced variable through
** the reference (&ref_name) and store it in a pointer, which is what I do in
** HumanB. This can also be done for HumanA just as easily. What separates
** HumanA is that HumanA is always armed, and HumanB can be unarmed. To
** illustrate this I've included a third example where Jim is unarmed, which I
** handle by checking for a NULL pointer in the HumanB.attack() function.
**
** Honestly though this whole approach seems bonkers to me. I would store HumanA
** data directly within the HumanA instance, not in a referenced variable from
** another scope. So in my opinion it isn't "appropriate" to store the weapon as
** a reference OR as a pointer in this case. It's appropriate to store it within
** the Human instances and access them within their proper scope. :p But okay,
** yeah, I get it. References are const aliases, pointers are variables. xD
*/

int	main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	//My test
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}