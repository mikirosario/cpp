/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:50:02 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 23:49:13 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain_str("HI THIS IS BRAIN");
	std::string	*brain_ptr = &brain_str;
	std::string &brain_ref = brain_str;

	std::cout << "String Address: " << &brain_str << std::endl
			<< "String Pointer: " << brain_ptr << std::endl
			<< "String Reference: " << &brain_ref << std::endl
			<< "String via ptr: " << *brain_ptr << std::endl
			<< "String via ref: " << brain_ref << std::endl;
	
	return (0);
}
