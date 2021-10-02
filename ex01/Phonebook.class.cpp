/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:23:19 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/02 18:50:36 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) : indexed(0)
{
}

bool	isNumber(char *str)
{
	for (size_t i = 0; str[i]; i++)
		if (std::isdigit(str[i]) == 0)
			return (false);
	return (true);
}

/*
** This function handles contact adding, and will be called when the user inputs
** the ADD command. We use the Contact class, which has two string arrays, one
** variable array called input_data and another static const array called
** input_msg, each with five string instances. The data strings are for storing
** user input, and the message strings are for storing user prompts associated
** with each input and stored as literal string constants defined in the
** Contact.class.cpp define file. They are static since they are class-specific
** and not member-specific, so their memory space should be shared by all
** classes, and constants since they should never be changed.
**
** We receive the address of an array of 8 Contact instances as an argument.
**
** We declare a static int i, which is initialized to 0 and used to iterate
** through the different Contact instances in the array. Every time add_contact
** is called, it will increment by 1.
**
** We declare a local int x, which is used to iterate through the different
** string instances in the input_data and input_msg arrays. These arrays
** represent the input fields of a contact and are in the following order:
**
** First name
** Last name
** Nickname
** Phone number
** Darkest secret
**
** So x will move from one field to another within a contact, and i will move
** from one contact to another within the phonebook.
**
** We have a cstring named buff used as a buffer, of size FIELD_BUFF_SIZE.
**
** If we are have gone through all 8 contacts (i == 8), then we want to loop
** back to the oldest contact, which will be the contact at phonebook[0], so we
** reset i to 0 if i is greater than 7.
**
** When we enter the add_contact function, we have a WHILE loop that loops until
** we have reached the fifth data item. 
**
** //THE WHILE LOOP\\
**
** - The bzero function is used to zero the buffer at the start of every loop.
** - Then we display the input message associated with the current field (as
** defined by the x variable).
** - Then we use cin.getline and our buffer to wait for user input and retrieve
** it.
** - The cin.getline method will retrieve only enough characters to fill the
** buffer size passed as an argument (in bytes). If the user inputs more than
** that, cin.getline will fill the buffer up to the limit (FIELD_BUFF_SIZE-1,
** because a cstring must be null terminated) and throw an error.
** - Then we use the cin_buff_overflow function to detect and handle a buffer
** overflow error. We will discard their input, so we will NOT increment x in
** this case, and instead prompt the user again for new input for the field.
** - If cin_buff_overflow detects that the user has overflowed the buffer, we
** will warn them that they need to input fewer characters on the console before
** prompting them for input again.
** - If the input was valid, we will copy the buff string to the corresponding
** input_data instance (as defined by x) within the current contact (as defined
** by i) and then increment x to go to the next field in the contact.
**
** When all five fields have been filled with valid data, we exit the while and
** increment i to go to the next contact and return from the function.
*/

void	Phonebook::addContact(void)
{
	static int	index = 0;
	int			field = Contact::First_Name;
	char		buff[FIELD_BUFF_SIZE];

	if (index > CONTACT_MAX-1)
		index = 0;
	while (field < FIELD_NUM)
	{
		bzero(buff, FIELD_BUFF_SIZE);
		Contact::showFieldPrompt(field);
		std::cin.getline(buff, FIELD_BUFF_SIZE);
		if (cin_buff_overflow(FIELD_BUFF_SIZE))
			std::cout << RED << "Too many characters. Use " << FIELD_BUFF_SIZE-1 \
			<< " characters or less." << RESET << std::endl;
		else
			this->contact[index].setFieldData(field++, buff);
	}

// //debug code	
// 	for (field = Contact::First_Name; field <= Contact::Darkest_Secret; field++)
// 	{
// 		std::cout << GRN;
// 		Contact::showFieldPrompt(field);
// 		this->contact[index].showFieldData(field);
// 		std::cout << RESET << std::endl;
// 	}	
// // debug code
	index++;
	this->changeIndexed(1);
	return ;
}

void	Phonebook::searchContact(void)
{
	char	buff[Contact::index_buf_size];
	//print header
	std::cout << "|" << std::setw(10) << "Index" << "|";
	for (size_t field = Contact::First_Name; field <= Contact::Nickname; field++)
	{
		std::cout << std::setw(10);
		Contact::showFieldName(field);
		std::cout << "|";
	}
	std::cout << std::endl;
	
	if (this->indexed < 1)
	{
		std::cout << RED << "You are friendless" << RESET << std::endl;
		return ;
	}
	//print contacts
	for (size_t index = 0; index < this->getIndexed(); index++)
	{
		std::cout << "|" << std::setw(10) << index+1 << "|";
		for (int field = Contact::First_Name; field <= Contact::Nickname; field++)
		{
			if (this->contact[index].getFieldDataLength(field) <= 10)
			{ //len sin width, width sin len :p
				std::cout << std::setw(10);
				this->contact[index].showFieldData(field);
			}
			else
			{
				this->contact[index].showFieldData(field, 9);
				std::cout << ".";
			}
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	//prompt for contact index
	int	contact;
	while (1)
	{
		bzero(buff, Contact::index_buf_size);
		std::cout << "Enter an index #: ";
		std::cin.getline(buff, Contact::index_buf_size);
		if (cin_buff_overflow(Contact::index_buf_size))
			std::cout << RED << "Too many characters. Use " << Contact::index_buf_size-1 \
			<< " characters or less." << RESET << std::endl;
		else if (isNumber(buff) == false)
			std::cout << RED << "Not a number" << RESET << std::endl;
		else if ((contact = std::atoi(buff)) < 1 || (size_t)contact > this->getIndexed())
			std::cout << RED << "Index does not exist " << RESET << std::endl;
		else
			break ;
	}
	//print contact
	for (int field = Contact::First_Name; field <= Contact::Darkest_Secret; field++)
	{
			std::cout << GRN;
			Contact::showFieldPrompt(field);
			this->contact[contact-1].showFieldData(field);
			std::cout << RESET << std::endl;
	}
	return ;
}

void	Phonebook::changeIndexed(int n)
{
	if (this->indexed + n < CONTACT_MAX)
		this->indexed += n;
	return ;
}

size_t	Phonebook::getIndexed(void)
{
	return (this->indexed);
}