/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:55:32 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/24 00:07:58 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#define GRN "\e[1;32m"
#define RST "\e[0m"

template<typename ARR_PTR_T, typename ARR_LEN_T, typename FUN_T>
void	iter(ARR_PTR_T arr_ptr, ARR_LEN_T const arr_len, FUN_T const fun)
{
	for (ARR_LEN_T i = 0; i < arr_len; ++i)
		std::cout << " " << arr_ptr[i];
	std::cout << std::endl;
	for (ARR_LEN_T i = 0; i < arr_len; ++i)
		arr_ptr[i] = fun(arr_ptr[i]);
	for (ARR_LEN_T i = 0; i < arr_len; ++i)
		std::cout << " " << arr_ptr[i];
	std::cout << std::endl;
}

template<typename T>
T	funky_func(T a)
{
	return  (++a);
}

template<typename T>
T	halve(T a)
{
	return (a / 2);
}

#endif
