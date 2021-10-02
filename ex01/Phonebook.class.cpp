/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:23:19 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/02 21:30:17 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) : indexed(0)
{
}

static size_t	calculate_index_buf_size(size_t contact_max)
{
	size_t	index_buf_size = 0;
	
	while (contact_max > 0)
	{
		index_buf_size++;
		contact_max /= 10;
	}
	return (index_buf_size+1);
}

static bool	isNumber(char *str)
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

static void	print_header(void)
{
	//print header
	std::cout << "|" << std::setw(10) << "Index" << "|";
	for (size_t field = Contact::First_Name; field <= Contact::Nickname; field++)
	{
		std::cout << std::setw(10);
		Contact::showFieldName(field);
		std::cout << "|";
	}
	std::cout << std::endl;
	return ;
}

/*
** This function prints a list of contacts stored in the Phonebook object.
**
** First we check the indexed variable to determine whether any contacts have
** been indexed. If no contacts have been indexed, we inform the user and return
** false. Otherwise, we run a for loop to retrieve some data for every indexed
** contact within this Phonebook instance.
**
** For each contact, first we print its index position number + 1 (so, Contact 0
** will be displayed to the user as Contact 1, etc.). Then we display the data
** associated with each field from First Name until Nickname (the first 3
** fields). If any of this data is at least 10 characters long or less, we pad
** it on the left with spaces using the std::setw method so that it occupies a
** column 10 characters wide. If the data is longer than 10 characters, we print
** only the first 9 characters followed by a '.'. Columns are enclosed by '|'.
**
** After all contacts have been listed, we return true.
*/

bool	Phonebook::print_contact_list(void)
{
	if (this->indexed < 1)
	{
		std::cout << RED << "You are friendless" << RESET << std::endl;
		return (false);
	}
	for (size_t index = 0; index < this->indexed; index++)
	{
		std::cout << "|" << std::setw(10) << index+1 << "|";
		for (int field = Contact::First_Name; field <= Contact::Nickname; field++)
		{
			if (this->contact[index].getFieldDataLength(field) <= 10)
			{
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
	return (true);
}

/*
** This function will prompt the user to provide a contact index for which to
** display details and retrieve the index provided by the user.
**
** The maximum number of characters that a user may enter here is equal to the
** number of digits in the CONTACT_MAX constant, which is calculated upon class
** initialization and saved as the index_buf_size constant. If the user inputs
** more characters than this, a message is displayed informing them of the
** maximum character limit and they are prompted again. The cin_buff_overflow
** function is used to handle the getline fail bit and remaining characters in
** the cin buffer.
**
** Otherwise, if any of the characters are not numbers, the user is informed and
** prompted again.
**
** Otherwise, the number is converted from alphanumeric format to an integer. If
** the number is negative or greater than the number of indexed contacts. the
** user is informed that it does not exist and is prompted again.
**
** Otherwise, the we leave the while and return the index number.
*/

int		Phonebook::prompt_for_contact_index(void)
{
	char	buff[Phonebook::index_buf_size];
	int	index;

	while (1)
	{
		bzero(buff, Phonebook::index_buf_size);
		std::cout << "Enter an index #: ";
		std::cin.getline(buff, Phonebook::index_buf_size);
		if (cin_buff_overflow(Phonebook::index_buf_size))
			std::cout << RED << "Too many characters. Use " << Phonebook::index_buf_size-1 \
			<< " characters or less." << RESET << std::endl;
		else if (isNumber(buff) == false)
			std::cout << RED << "Not a number" << RESET << std::endl;
		else if ((index = std::atoi(buff)) < 1 || (size_t)index > this->indexed)
			std::cout << RED << "Index does not exist " << RESET << std::endl;
		else
			break ;
	}
	return (index);
}

/*
** This function prints the contact details for the contact at the position
** 'index' within the Phonebook's field data array, one field at a time line by
** line, preceded by the field names.
*/

void	Phonebook::print_contact_details(int index)
{
	for (int field = Contact::First_Name; field < FIELD_NUM; field++)
	{
			std::cout << GRN;
			Contact::showFieldPrompt(field);
			this->contact[index-1].showFieldData(field);
			std::cout << RESET << std::endl;
	}
}

/*
** This function displays a list of contacts in the Phonebook to the user and
** prompts the user for a contact index number. It then provides the user with
** the contact details for the contact at the specified index and returns to the
** command prompt.
**
** If no contacts exist in the Phonebook, the user is informed and returned to
** the command prompt.
*/

void	Phonebook::searchContact(void)
{

	print_header();
	if (this->print_contact_list())
		this->print_contact_details(this->prompt_for_contact_index());
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

const size_t Phonebook::index_buf_size = calculate_index_buf_size(CONTACT_MAX);