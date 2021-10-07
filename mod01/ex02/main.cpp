/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:50:02 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/07 02:53:50 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain_str("HI THIS IS BRAIN");
	std::string	*stringPTR = &brain_str;
	std::string &stringREF = brain_str;

	std::cout << "String Address: " << &brain_str << std::endl
			<< "String Pointer: " << stringPTR << std::endl
			<< "String Reference: " << &stringREF << std::endl
			<< "String via ptr: " << *stringPTR << std::endl
			<< "String via ref: " << stringREF << std::endl;
	
	return (0);
}
