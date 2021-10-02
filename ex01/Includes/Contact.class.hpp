/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:25:17 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/02 18:42:20 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include "Phonebook_constants.hpp"

class	Contact {
	public:
		static const size_t			index_buf_size;
		void						showFieldData(int field);
		void						showFieldData(int field, size_t len);
		static void					showFieldName(int field);
		static void					showFieldPrompt(int field);
		bool						setFieldData(int field, char *data);
		size_t						getFieldDataLength(int field);
		enum Field
		{
			First_Name = 0,
			Last_Name,
			Nickname,
			Phone_Number,
			Darkest_Secret
		};

	private:
		std::string					input_data[FIELD_NUM];
		static const std::string	input_msg[FIELD_NUM];


	//me vale con los que vienen por defecto :p
	//Contact(void);
	// ~Contact(void);
};

#endif