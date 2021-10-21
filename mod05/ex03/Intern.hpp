/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:02:26 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 05:26:20 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include <iostream>
#include <exception>
#include "Form.hpp"


class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);
		Intern &		operator=(Intern const & src);
		class RequestedFormUnknownException : public std::exception
		{
			public:
				char const * what() const throw();
		};
		Form const *	makeForm(std::string const & name, std::string const & target) const throw(Intern::RequestedFormUnknownException);
};

#endif
