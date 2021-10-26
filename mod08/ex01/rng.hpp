/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 08:07:26 by miki              #+#    #+#             */
/*   Updated: 2021/10/26 06:44:44 by mrosario         ###   ########.fr       */
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
		rng(rng const & src);
		rng &	operator=(rng const & src);
		static int	negative_offset;
		static rng	singleton;
	public:
		~rng(void);
		static int	randomInt(void);
};

#endif