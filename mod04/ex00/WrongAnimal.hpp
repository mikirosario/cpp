/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:34:27 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/13 16:48:07 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
		bool		has_name;
	public:
		WrongAnimal(void);
		WrongAnimal (std::string const &src);
		WrongAnimal (WrongAnimal const &src);
		virtual ~WrongAnimal(void);
		WrongAnimal			&operator=(WrongAnimal const &src);
		void				makeSound(void) const;
		std::string const	&getType(void) const;
};

#endif
