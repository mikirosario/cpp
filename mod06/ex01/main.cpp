/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:42:08 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 02:06:12 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.hpp"
#include "serializer.hpp"

int	main(void)
{
	Data	hungry;
	char	c = 'z';

	hungry.jamon = 1;
	hungry.milanesa = &c;
	hungry.paella = 100;
	hungry.muffin = 'A';
	hungry.pizza = 56;
	hungry.taco = '*';

	uintptr_t	serialized_ptr = serialize(&hungry);

	Data	*ptr = deserialize(serialized_ptr);

	std::cout << "Jamon: " << ptr->jamon << std::endl
	<< "Milanesa: " << *ptr->milanesa << std::endl
	<< "Paella: " << ptr->paella << std::endl
	<< "Muffin: " << ptr->muffin << std::endl
	<< "Pizza: " << ptr->pizza << std::endl
	<< "Taco: " << ptr->taco << std::endl;
}