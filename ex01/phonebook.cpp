/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:18:57 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/01 06:58:25 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstring>
#include <fstream>

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
** We zero the character buffer. Then we prompt the user to state their command.
** We declare a character array of eight bytes, because the longest command will
** not be longer than that ('SEARCH') and use the getline member function of the
** istream instance cin to retrieve no more than BUFSIZE characters from stdin.
**
** The getline member function works with cstrings, so I also load the cstring
** lib to get bzero for it.
**
** If getline extracts no characters OR no delimiting character ('\ n' newline
** in this case) is found after BUFSIZE-1 characters are read, it will set the
** fail bit of the cin instance (which we can detect by using the cin.fail member
** function). The gcount member function of cin will return the number of
** characters extracted in the last unformatted input operation on the cin object
** (i.e. the getline member function).
**
** Thus, if the fail bit is set AND the gcount is BUFSIZE-1, we know the user
** overflowed my buffer. The remaining input by the user is left in the cin
** buffer. If I don't do anything about it, for reasons I don't yet understand
** it causes infinite looping, with a null character apparently being extracted?
** To prevent this I make sure to null terminate the end of the buffer, I use
** clear member function, which clears the fail bit, and then I use cin.ignore
** up to the streamsize max limit or until the next '\n' to ignore everything
** else accumulated in the buffer.
**
** Whew.
**
** I assign the buff array address to a string object and use the string.compare
** member function to compare the string with all key words. If EXIT is detected
** we exit. If ADDED is detected, we will do ADDED operations. If SEARCH is
** detected, we will do SEARCH operations. If anything else is detected, we will
** ignore it and prompt the user again.
*/

int	inputloop (void)
{
	char			buff[8];
	int const		BUFSIZE = 8;
	std::string		linebuff;

	while (1)
	{
		bzero(buff, BUFSIZE);
		std::cout << "State your command, master: ";
		std::cin.getline(buff, BUFSIZE);
		if (std::cin.fail() && std::cin.gcount() == BUFSIZE-1)
		{
			buff[BUFSIZE-1] = '\0';
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		linebuff = buff;
		if (!linebuff.compare("EXIT"))
			return (0);
		else if (!linebuff.compare("ADD"))
			std::cout << "ADDED" << std::endl;
		else if (!linebuff.compare("SEARCH"))
			std::cout << "SEARCH" << std::endl;
	}
}

int main (void)
{
	print_intro();
	inputloop();

	return (0);
}