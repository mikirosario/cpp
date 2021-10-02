/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:21:11 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/02 20:48:37 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

/*
** This member function displays on the terminal the data stored for the field
** passed as 'field' within the Contact.

** The field data is a string instance in the input_data string array at the
** position 'field'. The input_data array contains the data input by the user
** for the 'field' within the Contact object.
**
** If the 'field' passed as an argument is not present in the array, false is
** returned. Otherwise, true is returned.
*/

void	Contact::showFieldData(int field)
{
	if (field < 0 || field > FIELD_NUM-1)
		return ;
	std::cout << this->input_data[field];
	return ;
}

/*
** If the showFieldData function is passed a length, it will display the field
** only up to 'len' bytes. Doesn't take Unicode into account, but I'm not going
** to go *that* crazy over this project. It's still the 80s, after all. ;)
**
** If the length is greater than the field length, it will display the whole
** field.
*/

void	Contact::showFieldData(int field, size_t len)
{
	if (field < 0 || field > FIELD_NUM-1)
		return ;
	std::cout << this->input_data[field].substr(0, len);
	return ;
}

/*
** This member function displays on the terminal the name of the field passed as
** 'field' within the Contact.
**
** The name is a string instance in the input_msg string array at the position
** 'field'. The input_msg array contains the names of every field within a
** Contact object.
**
** If the 'field' passed as an argument is not present in the array, false is
** returned. Otherwise, true is returned.
*/

void Contact::showFieldName(int field)
{
	if (field < 0 || field > FIELD_NUM-1)
		return ;
	std::cout << Contact::input_msg[field];
	return ;
}

/*
** This member function displays field names as a user prompt, that is, followed
** by a colon and a space (i.e. "First Name: ", "Last Name: ", etc.).
*/

void Contact::showFieldPrompt(int field)
{
	if (field < 0 || field > FIELD_NUM-1)
		return ;
	std::cout << Contact::input_msg[field] << ": ";
	return ;
}
/*
** This member function copies the string pointed to by the pointer 'data' to
** the string instance in the input_data string array at the position 'field'.
**
** If the 'field' passed as an argument is not present in the array, nothing is
** done and the function returns false. Otherwise, the copy is made and the
** function returns true. 
*/

bool Contact::setFieldData(int field, char *data)
{
	if (field < 0 || field > FIELD_NUM-1)
		return (false);
	this->input_data[field] = data;
	return (true);
}

/*
** This member function returns the length of the field passed as 'field'. If
** no such field exists, 0 is returned.
*/

size_t	Contact::getFieldDataLength(int field)
{
	if (field < 0 || field > FIELD_NUM-1)
		return (0);
	return (this->input_data[field].length());
}

const std::string Contact::input_msg[] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};