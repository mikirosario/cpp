/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:41:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/03 19:10:26 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
