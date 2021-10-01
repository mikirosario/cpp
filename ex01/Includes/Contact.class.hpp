/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:25:17 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/01 19:24:29 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class	Contact {
	public:

	// std::string					first_name;
	// std::string					last_name;
	// std::string					nickname;
	// std::string					phone_number;
	// std::string					darkest_secret;
	std::string					input_data[5];
	static const std::string	input_msg[5];
	static size_t				indexed;

	//me vale con los que vienen por defecto :p
	//Contact(void);
	// ~Contact(void);
};

#endif