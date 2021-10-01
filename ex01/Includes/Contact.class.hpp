/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:25:17 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/01 20:26:53 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include "phonebook.hpp"

class	Contact {
	public:

	// std::string					first_name;
	// std::string					last_name;
	// std::string					nickname;
	// std::string					phone_number;
	// std::string					darkest_secret;
	std::string					input_data[FIELD_NUM];
	static const std::string	input_msg[FIELD_NUM];
	static size_t				indexed;
	static const size_t			index_buf_size;
	enum Field
	{
		First_Name = 0,
		Last_Name,
		Nickname,
		Phone_Number,
		Darkest_Secret
	};

	//me vale con los que vienen por defecto :p
	//Contact(void);
	// ~Contact(void);
};

#endif