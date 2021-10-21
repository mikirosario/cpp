/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:39:42 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 02:59:15 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;
		ShrubberyCreationForm(void);
	protected:
		void	action(void) const throw(std::exception,std::string);
	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
};

#endif
