/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:09:45 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/23 23:13:23 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main(void)
{
	char	chr_array[] = {"Hello World"};
	int		int_array[2] = {4,2};
	
	iter(chr_array, std::strlen(chr_array));
	std::cout << std::endl;
	iter(int_array, 2);

	return (0);
}