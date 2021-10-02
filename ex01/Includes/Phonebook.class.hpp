/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:15:37 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/02 18:41:13 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include "Phonebook_constants.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define RESET "\e[0m"

class	Phonebook {
	public:
		Phonebook();
		void	addContact();
		void	searchContact();
		size_t	getIndexed(void);
		void	changeIndexed(int n);
	
	private:
		Contact		contact[CONTACT_MAX];
		size_t		indexed;
};

int		cin_buff_overflow(int bufsize);

#endif