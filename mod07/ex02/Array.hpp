/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:30:13 by miki              #+#    #+#             */
/*   Updated: 2021/10/24 03:55:53 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#define MEMALLOC_FAIL_MSG std::cerr << "Memory allocation failed" << std::endl

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		unsigned int	_last_pos;
		T * 			_arr;
		static void	copy_array(T * dest_arr, T const * src_arr, unsigned int size) {
			for (unsigned int i = 0; i < size; ++i)
				dest_arr[i] = src_arr[i];
		}
	public:
		Array(void) : _size(0), _last_pos(0), _arr(new T[0]) {
			if (this->_arr == NULL)
				MEMALLOC_FAIL_MSG;
		}
		Array(unsigned int const & n) : _size(n), _last_pos(n > 0 ? n - 1 : 0), _arr(new T[n]) {
			if (this->_arr == NULL)
			{
				this->_size = 0;
				this->_last_pos = 0;
				MEMALLOC_FAIL_MSG;
			}				
		}
		Array(Array const & src) : _size(src._size), _last_pos(src._last_pos), _arr(new T[this->_size]) {
			if (this->_arr)
				copy_array(this->_arr, src._arr, this->_size);
			else
			{
				this->_size = 0;
				this->_last_pos = 0;
				MEMALLOC_FAIL_MSG;
			}
		}
		~Array(void) {
			if (this->_arr)
				delete[] this->_arr;
			_arr = NULL;
		}
		Array &		operator=(Array const & src) {
			T * 			new_array;
			unsigned int	new_size = src._size;

			if ((new_array = new T[new_size]) == NULL)
				MEMALLOC_FAIL_MSG;
			else
			{
				if (this->_arr)			
					delete[] this->_arr;
				this->_size = new_size;
				this->_last_pos = src._last_pos;
				this->_arr = new_array;
				copy_array(this->_arr, src._arr, this->_size);
			}
			return (*this);
		}
		T &		operator[](unsigned int n) throw(std::exception) {
			if (this->_size == 0 || n > this->_last_pos) //prob pre-calculate
				throw std::exception();
			return (this->_arr[n]);
		}
		unsigned int	size(void) { return (this->_size); }
};

#endif
