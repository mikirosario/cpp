/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:40:14 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/21 02:59:08 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	_target;
		RobotomyRequestForm(void);
	protected:
		void	action(void) const;
	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm &	operator=(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);
};

#endif
