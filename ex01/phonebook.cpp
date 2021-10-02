#include <iostream>
#include <fstream>
#include "Phonebook.class.hpp"

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
** I assign the buff array address to a string object and use the string.compare
** member function to compare the string with all key words. If EXIT is detected
** we exit. If ADDED is detected, we will do ADDED operations. If SEARCH is
** detected, we will do SEARCH operations. If anything else is detected, we will
** ignore it and prompt the user again.
*/

int	inputloop (Phonebook *phonebook)
{
	char			buff[COMMAND_BUFF_SIZE];
	std::string		linebuff;

	while (1)
	{
		bzero(buff, COMMAND_BUFF_SIZE);
		std::cout << "State your command, master [ADD, SEARCH, EXIT]: ";
		std::cin.getline(buff, COMMAND_BUFF_SIZE);
		cin_buff_overflow(COMMAND_BUFF_SIZE);
		linebuff = buff;
		if (!linebuff.compare("EXIT"))
			return (0);
		else if (!linebuff.compare("ADD"))
			phonebook->addContact();
		else if (!linebuff.compare("SEARCH"))
			phonebook->searchContact();
	}
}

int main (void)
{
	Phonebook phonebook;
	print_intro();
	inputloop(&phonebook);

	return (0);
}