/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:25:17 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/03 17:59:21 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include "Phonebook_constants.hpp"

class	Contact {
	public:
		void						showFieldData(int field);
		void						showFieldData(int field, size_t len);
		static void					showFieldName(int field);
		static void					showFieldPrompt(int field);
		bool						setFieldData(int field, char *data);
		size_t						getFieldDataLength(int field);

	private:
		std::string					_input_data[TOTAL_FIELD_NUM];
		static const std::string	_input_msg[TOTAL_FIELD_NUM];
};

#endif
