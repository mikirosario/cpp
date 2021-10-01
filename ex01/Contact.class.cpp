/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:21:11 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/01 21:11:10 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "phonebook.hpp"

// Contact::Contact(void) : first_name(NULL), last_name(NULL), nickname(NULL),
// phone_number(NULL), darkest_secret(NULL), input_msg[0]("First Name: ") {
	
// }
size_t	calculate_index_buf_size(size_t contact_max)
{
	size_t	index_buf_size = 0;
	
	while (contact_max > 0)
	{
		index_buf_size++;
		contact_max /= 10;
	}
	return (index_buf_size+1);
}

const std::string Contact::input_msg[] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
size_t Contact::indexed = 0;
const size_t Contact::index_buf_size = calculate_index_buf_size(CONTACT_MAX);