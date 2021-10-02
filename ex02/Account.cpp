/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 22:59:55 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/03 00:00:12 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Account.hpp"

typedef std::vector<Account::t>							  accounts_t;

int	const	amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
accounts_t				accounts( amounts, amounts + amounts_size );

int	main(void)

{
	//std::cout << sizeof(amounts) / sizeof(int) << std::endl;
	std::cout << accounts << std::endl;
	return (0);
}