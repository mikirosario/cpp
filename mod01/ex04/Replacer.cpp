/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:37:29 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/07 02:41:46 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <cstring>

void	Replacer::_closeFiles(void)
{
	if (this->_original_file.is_open())
		this->_original_file.close();
	if  (this->_new_file.is_open())
		this->_new_file.close();
}

bool	Replacer::fileOpenSuccess(void)
{
	if (this->_original_file.fail())
		std::cerr << this->_original_filename << ": " << std::strerror(errno) << std::endl;
	else if (this->_new_file.fail())
		std::cerr << this->_new_filename << ": " << std::strerror(errno) << std::endl;
	else
		return (true);
	return (false);
}

bool	Replacer::_fileCloseSuccess(void)
{
	if (this->_original_file.is_open() || this->_new_file.is_open())
		return (false);
	return (true);
}

Replacer::Replacer(const std::string filename) : _original_filename(filename)
{	
	this->_new_filename = filename;
	this->_new_filename += ".replace";
	this->_original_file.open(filename);
	if (this->_original_file.is_open())
		this->_new_file.open(this->_new_filename);
}

Replacer::~Replacer()
{
	this->_closeFiles();
}

void	Replacer::setFile(const std::string filename)
{
	this->_closeFiles();
	if (this->_fileCloseSuccess())
	{
		this->_original_filename = filename;
		this->_original_file.open(filename);
		if (this->_original_file.is_open())
			this->_new_file.open(this->_new_filename);
	}
}

void	Replacer::Replace(const std::string s1, const std::string s2)
{
	std::string		linebuf;

	if (fileOpenSuccess())
		while (std::getline(this->_original_file, linebuf))
		{
			for (size_t pos = 0; (pos = linebuf.find(s1, pos)) < linebuf.npos; )
			{
				linebuf.erase(pos, s1.length());
				linebuf.insert(pos, s2);
				pos += s2.length();
			}
			this->_new_file << linebuf << std::endl;
		}
	return ;
}
