/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:18:57 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/01 18:29:55 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "phonebook.hpp"
#include "Contact.class.hpp"
#include "ANSI_colors.hpp"

/*
** This function is for buffer overflow handling.
**
** I don't like allowing the user to input an unlimited number of characters to
** my buffer, so I restrict field lengths. I use cin.getline(buff, BUFSIZE) to
** control this. If the user inputs more than BUFSIZE-1 characters for a given
** buffer, getline will extract only up to BUFSIZE-1 characters and ignore the
** rest. The cin.getline function uses a cstring buffer, and cstrings are always
** null-terminated, hence the -1. The BUFSIZE includes the null terminator. The
** rest of the user input will remain in the cin buffer. This function is to
** handle the resulting situation so the cin buffer is cleared and ready for
** new user input.
**
** If getline extracts no characters OR no delimiting character ('\n' by
** default) is found after BUFSIZE-1 characters are read, it will set the fail
** bit of the cin instance (which we can detect by using the cin.fail member
** function). The gcount member function of cin will return the number of
** characters extracted in the last unformatted input operation on the cin
** object (i.e. the getline function, in this case).
**
** Thus, if the fail bit is set AND the gcount is BUFSIZE-1, we know the user
** input was bigger than our buffer and truncated by getline, which means the
** cin buffer needs to be cleared. So first we test for this condition.
**
** If we don't clear the cin buffer, it causes infinite looping. This seems to
** be related to the fail bit. I think that if the fail bit isn't reset, the
** cin.getline function just keeps failing over and over again, causing the
** input loop to loop infinitely.
**
** To prevent this, I use cin.clear member function, which clears the fail bit,
** and then I use cin.ignore up to the streamsize max limit or until the next
** '\n' to ignore everything else accumulated in the cin buffer, so that it
** isn't extracted in subsequent input loops.
**
** Whew. Done!
**
** Then I return 0 or 1 to indicate whether an overflow occurred for further
** optional handling by the calling function, as desired.
*/

int	cin_buff_overflow(int bufsize)
{
	if (std::cin.fail() && std::cin.gcount() == bufsize-1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (1);
	}
	return (0);
}

/*
** Just a bit of fun. ;) At least opening files is a lot less tedious on C++!
*/

void	print_intro(void)
{
	std::string		linebuff;
	std::ifstream	intro;

	intro.open("intro.txt");
	if (intro.is_open())
	{
		while (std::getline(intro, linebuff))
			std::cout << linebuff << std::endl;
		intro.close();
	}
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

void		add_contact(Contact *phonebook)
{
	static int	i = 0;
	int			x = 0;
	char		buff[FIELD_BUFF_SIZE];
	//std::string	linebuff;

	//provisional, probarlo cuando search esté funcionando
	if (i > 7)
		i = 0;
	while (x < 5)
	{
		bzero(buff, FIELD_BUFF_SIZE);
		std::cout << Contact::input_msg[x] << ": ";
		std::cin.getline(buff, FIELD_BUFF_SIZE);
		if (cin_buff_overflow(FIELD_BUFF_SIZE))
			std::cout << RED << "Too many characters. Use " << FIELD_BUFF_SIZE-1 \
			<< " characters or less." << RESET << std::endl;
		else
			phonebook[i].input_data[x++] = buff;
	}
	for (int index = 0; index < 5; index++)
		std::cout << GRN << Contact::input_msg[index] << ": " << phonebook[i].input_data[index] << RESET << std::endl;
	i++;
	if (Contact::indexed < 8)
		Contact::indexed++;
	return ;
}

/*
** This function handles contact searching and will be called when the user
** inputs the SEARCH command.
*/

void		search_contact(Contact *phonebook)
{
	//print header
	std::cout << "|" << std::setw(10) << "Index" << "|";
	for (size_t i = 0; i < 3; i++)
		std::cout << std::setw(10) << Contact::input_msg[i] << "|";
	std::cout << std::endl;
	//print contacts
	for (size_t index = 0; index < Contact::indexed; index++)
	{
		std::cout << "|" << std::setw(10) << index+1 << "|";
		for (size_t field = 0; field < 3; field++)
		{
			if (phonebook[index].input_data[field].length() <= 10)
				std::cout << std::setw(10) << phonebook[index].input_data[field];
			else
				std::cout << phonebook[index].input_data[field].substr(0, 9) << ".";
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	return ;
}

/*
** We zero the character buffer. Then we prompt the user to state their command.
** We declare a character array of eight bytes, because the longest command will
** not be longer than that ('SEARCH') and use the getline member function of the
** istream instance cin to retrieve no more than BUFSIZE characters from stdin.
**
** I assign the buff array address to a string object and use the string.compare
** member function to compare the string with all key words. If EXIT is detected
** we exit. If ADDED is detected, we will do ADDED operations. If SEARCH is
** detected, we will do SEARCH operations. If anything else is detected, we will
** ignore it and prompt the user again.
*/

int	inputloop (Contact *phonebook)
{
	char			buff[COMMAND_BUFF_SIZE];
	std::string		linebuff;

	//std::cin.setf(std::cin.uppercase);
	while (1)
	{
		bzero(buff, COMMAND_BUFF_SIZE);
		std::cout << "State your command, master: ";
		std::cin.getline(buff, COMMAND_BUFF_SIZE);
		// if (std::cin.fail() && std::cin.gcount() == BUFSIZE-1)
		// {
		// 	buff[BUFSIZE-1] = '\0';
		// 	std::cin.clear();
		// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// }
		cin_buff_overflow(COMMAND_BUFF_SIZE);
		linebuff = buff;
		if (!linebuff.compare("EXIT"))
			return (0);
		else if (!linebuff.compare("ADD"))
			add_contact(phonebook);
			//std::cout << "ADDED" << std::endl;
		else if (!linebuff.compare("SEARCH"))
			search_contact(phonebook);
			//std::cout << "SEARCH" << std::endl;
	}
}

int main (void)
{
	Contact	phonebook[8];

	print_intro();
	inputloop(phonebook);

	return (0);
}