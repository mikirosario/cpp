/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:09:45 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/24 00:08:08 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main(void)
{
	char	chr_array[] = {"abcdefghijklmn"};
	int		int_array[2] = {4,2};
	float	float_array[2] = {4.42, 100.1};
	
	std::cout << "FUNKY FUNC" << std::endl;
	iter(chr_array, std::strlen(chr_array), funky_func<char>);
	std::cout << std::endl;
	iter(int_array, 2, funky_func<int>);
	std::cout << std::endl;
	iter(float_array, 2, funky_func<float>);
	std::cout << std::endl;

	std::cout << "HALVE" << std::endl;
	iter(chr_array, std::strlen(chr_array), halve<char>);
	std::cout << std::endl;
	iter(int_array, 2, halve<int>);
	std::cout << std::endl;
	iter(float_array, 2, halve<float>);

	return (0);
}
