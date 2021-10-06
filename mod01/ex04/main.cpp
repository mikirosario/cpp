/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:54:30 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 13:15:44 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

bool	badArguments(int argc, const char **argv)
{
	if (argc != 4)
		std::cerr << "Error: Bad arguments. Enter arguments like this: [./replace filename str1 str2]" << std::endl;
	else if (!*argv[2] || !*argv[3])
		std::cerr << "Error: Empty string" << std::endl;
	else
		return (false);
	return (true);
}

int	main(int argc, const char **argv)
{
	if (badArguments(argc, argv))
		return (1);
	else
	{
		Replacer	replacer(argv[1]);
		replacer.Replace(argv[2], argv[3]);
		replacer.setFile("badfilename");
		replacer.Replace(argv[2], argv[3]);
	}
	return (0);
}
