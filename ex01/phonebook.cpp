/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:18:57 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/01 12:41:50 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>
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

int		add_contact(Contact *contacts)
{
	static int	i = 0;
	int			x = 0;
	char		buff[FIELD_BUFF_SIZE];
	std::string	linebuff;

	if (i > 7)
		return (0);
	while (x < 5)
	{
		bzero(buff, FIELD_BUFF_SIZE);
		std::cout << Contact::input_msg[x];
		std::cin.getline(buff, FIELD_BUFF_SIZE);
		if (cin_buff_overflow(FIELD_BUFF_SIZE))
			std::cout << RED << "Too many characters. Use " << FIELD_BUFF_SIZE-1 \
			<< " characters or less." << RESET << std::endl;
		else
			contacts[i].input_data[x++] = buff;
	}
	for (int index = 0; index < 5; index++)
		std::cout << GRN << Contact::input_msg[index] << contacts[i].input_data[index] << RESET << std::endl;
	i++;
	return (1);
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

int	inputloop (Contact *contacts)
{
	char			buff[COMMAND_BUFF_SIZE];
	std::string		linebuff;

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
			add_contact(contacts);
			//std::cout << "ADDED" << std::endl;
		else if (!linebuff.compare("SEARCH"))
			std::cout << "SEARCH" << std::endl;
	}
}

int main (void)
{
	Contact	contacts[8];
	print_intro();
	inputloop(contacts);

	return (0);
}