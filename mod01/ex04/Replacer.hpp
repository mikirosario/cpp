/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:33:30 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 00:57:37 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H

#include <iostream>
#include <fstream>

class	Replacer
{
	public:
		~Replacer();
		void	Replace(const std::string &filename, const std::string &s1,
		const std::string &s2);
	private:
		std::ifstream	_original_file;
		std::ofstream	_new_file;
		//const std::string	_new_filename;
		//const std::string	_linebuf;
		//const std::string	_s1;
		//const std::string	_s2;
};

#endif