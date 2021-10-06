/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:28:08 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/06 14:44:22 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Karen
{
private:
	void												debug(void);
	void												info(void);
	void												warning(void);
	void												error(void);
	void												level_does_not_exist(void);
	std::pair<std::string[4], void (Karen::*[5])(void)>	_pair;
	
public:
	Karen();
	void	complain(std::string level);
};
