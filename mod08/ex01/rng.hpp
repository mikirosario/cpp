/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 08:07:26 by miki              #+#    #+#             */
/*   Updated: 2021/10/25 10:23:52 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNG_H
# define RNG_H

#include <time.h>

#define MOD 1000

class rng
{
	private:
		rng(void);
		rng(rng const & src) = delete;
		rng &	operator=(rng const & src) = delete;
		static int	negative_offset;
		static rng	singleton;
	public:
		~rng(void);
		static int	randomInt(void);
};

#endif