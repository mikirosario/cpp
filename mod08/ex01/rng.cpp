/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miki <miki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 08:29:59 by miki              #+#    #+#             */
/*   Updated: 2021/10/25 10:23:04 by miki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rng.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>

rng	rng::singleton;

int	rng::negative_offset = MOD / 2;

rng::rng(void)
{
	struct timespec tp;
	clock_gettime(CLOCK_REALTIME, &tp);
	srand(tp.tv_nsec);
}
rng::~rng(void)
{}

int	rng::randomInt(void)
{
	return ((rand() % MOD) - negative_offset);
}
