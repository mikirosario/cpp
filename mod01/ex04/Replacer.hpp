/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:33:30 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 13:17:47 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H

#include <iostream>
#include <fstream>

class	Replacer
{
	public:
		Replacer(const std::string filename);
		~Replacer();
		void	setFile(const std::string filename);
		void	Replace(const std::string s1, const std::string s2);
		bool	fileOpenSuccess(void);
	private:
		std::ifstream		_original_file;
		std::ofstream		_new_file;
		std::string			_original_filename;
		std::string			_new_filename;
		void				_closeFiles(void);
		bool				_fileCloseSuccess(void);
};

#endif
