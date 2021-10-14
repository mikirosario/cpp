/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:02:41 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 22:29:59 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#define BRAIN_H_IDEAS 100

class Brain
{
	private:
		std::string 		ideas[BRAIN_H_IDEAS];
		std::string const	no_idea;
		size_t				ideas_held;
		size_t				index;
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);
		Brain				&operator=(Brain const &src);
		void 				setIdea(std::string const &idea);
		std::string	const	&getIdea(void);
};

#endif