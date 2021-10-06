/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:40:49 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 17:06:47 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen	karen;

	if (argc != 2)
	{
		std::cerr << "Pass as an argument a single log level [ DEBUG INFO WARNING ERROR ]" << std::endl;
		return (1);
	}
	karen.karenFilter(argv[1]);
	return (0);
}
