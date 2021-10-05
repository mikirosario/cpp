/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:54:30 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 00:57:59 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

namespace iamerror
{
	bool	badArguments(int argc, const char **argv)
	{
		if (argc != 4)
			std::cerr << "Error: Bad arguments. Enter arguments like this: [./replace filename str1 str2]" << std::endl;
		else if (!*argv[2] || !*argv[3])
			std::cerr << "Error: Empty string" << std::endl;
		else
			return (false);
		return (true);
	}

	bool	failedOpen(std::ifstream &file, const char *filename)
	{
		if (file.fail())
			std::cerr << filename << ": " << strerror(errno) << std::endl;
		else
			return (false);
		return (true);
	}

	bool	failedOpen(std::ofstream &file, std::string &filename)
	{
		if (file.fail())
			std::cerr << filename << ": " << strerror(errno) << std::endl;
		else
			return (false);
		return (true);
	}
}

namespace endprog
{
	void	closeOpenFiles(std::ifstream &original_file, std::ofstream &new_file)
	{
		if (original_file.is_open())
			original_file.close();
		if (new_file.is_open())
			new_file.close();
	}

	void	closeProg(std::ifstream &original_file, std::ofstream &new_file, bool fail)
	{
		closeOpenFiles(original_file, new_file);
		if (fail)
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	}
}

int	main(int argc, const char **argv)
{
	std::ifstream	original_file;
	std::ofstream	new_file;
	std::string		new_filename;
	std::string		linebuf;
	std::string		s1;
	std::string		s2;

	if (iamerror::badArguments(argc, argv))
		endprog::closeProg(original_file, new_file, 1);

	original_file.open(argv[1]);
	if (iamerror::failedOpen(original_file, argv[1]))
		endprog::closeProg(original_file, new_file, 1);
	new_filename = argv[1];
	new_filename += ".replace";
	new_file.open(new_filename);
	if (iamerror::failedOpen(new_file, new_filename))
		endprog::closeProg(original_file, new_file, 1);
	s1 = argv[2];
	s2 = argv[3];
	while (std::getline(original_file, linebuf))
	{
		if (linebuf == s1)
			new_file << s2 << std::endl;
		else
			new_file << linebuf << std::endl;
	}
	endprog::closeProg(original_file, new_file, 0);
}