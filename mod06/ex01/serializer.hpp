/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 01:46:10 by miki              #+#    #+#             */
/*   Updated: 2021/10/23 17:42:53 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include "data_struct.hpp"

uintptr_t	serialize(Data* ptr);
Data *		deserialize(uintptr_t raw);

#endif
