/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:55:32 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/23 23:14:15 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

template<typename ARR_PTR_T, typename ARR_LEN_T/*, typename FUN_T*/>
void	iter(ARR_PTR_T arr_ptr, ARR_LEN_T arr_len/*, FUN_T fun*/)
{
	for (ARR_LEN_T i = 0; i < arr_len; ++i)
		std::cout << arr_ptr[i];
	std::cout << std::endl;
}

#endif