/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:37:29 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 00:56:46 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

namespace endprog
{
	static void	closeOpenFiles(std::ifstream &original_file, std::ofstream &new_file)
	{
		if (original_file.is_open())
			original_file.close();
		if (new_file.is_open())
			new_file.close();
	}
}

Replacer::~Replacer()
{
	if (this->_original_file.is_open())
		this->_original_file.close();
	if  (this->_new_file.is_open())
		this->_new_file.close();
}

void	Replacer::Replace(const std::string &filename, const std::string &s1,
const std::string &s2)
{
	std::ifstream	original_file;
	std::ofstream	new_file;
	std::string		new_filename;
	std::string		linebuf;

	new_filename = filename;
	new_filename += ".replace";
	original_file.open(filename);
	new_file.open(new_filename);
	
	new_file.open()

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