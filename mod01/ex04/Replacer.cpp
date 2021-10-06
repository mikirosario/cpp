/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:37:29 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 13:18:01 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

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
		std::cerr << this->_original_filename << ": " << strerror(errno) << std::endl;
	else if (this->_new_file.fail())
		std::cerr << this->_new_filename << ": " << strerror(errno) << std::endl;
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
			if (linebuf == s1)
				this->_new_file << s2 << std::endl;
			else
				this->_new_file << linebuf << std::endl;
		}
	return ;
}
