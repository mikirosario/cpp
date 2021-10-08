/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:52:44 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/08 20:28:32 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a(4);

	std::cout << a.getRawBits() << std::endl;
	std::cout << a.toInt() << std::endl;

	return (0);
}