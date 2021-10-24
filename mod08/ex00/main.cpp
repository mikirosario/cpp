/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:52:40 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/25 01:32:10 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <list>
#include <deque>

int	main(void)
{
	int	*ptr;
	std::vector<int> arr;
	arr.push_back(4);
	arr.push_back(2);

	std::list<int> list;
	list.push_back(4);
	list.push_back(2);

	std::deque<int> deque;
	deque.push_back(4);
	deque.push_back(2);
	deque.push_back(9);
	deque.push_back(8);
	deque.push_back(14);
	deque.push_back(42);

	ptr = easyfind(arr, 2);
	if (ptr)
		std::cout << *ptr << std::endl;
	else
		std::cout << "Not present" << std::endl;
	
	ptr = easyfind(list, 2);
	if (ptr)
		std::cout << *ptr << std::endl;
	else
		std::cout << "Not present" << std::endl;

	ptr = easyfind(deque, 42);
	if (ptr)
		std::cout << *ptr << std::endl;
	else
		std::cout << "Not present" << std::endl;

	
	ptr = easyfind(arr, 9);
	if (ptr)
		std::cout << *ptr << std::endl;
	else
		std::cout << "Not present" << std::endl;
	
	ptr = easyfind(list, 0);
	if (ptr)
		std::cout << *ptr << std::endl;
	else
		std::cout << "Not present" << std::endl;

	ptr = easyfind(deque, 43);
	if (ptr)
		std::cout << *ptr << std::endl;
	else
		std::cout << "Not present" << std::endl;
	
	return (0);
}
