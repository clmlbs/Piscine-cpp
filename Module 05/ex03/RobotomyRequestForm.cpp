/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:32:08 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 18:55:42 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : _target("default_target"), \
Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target), \
Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : \
_target(src._target), Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) 
{ 
	return *this; 
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::action(void) const
{
	std::cout << "TTRACTRACTRACTRAC" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " was robotize with success" << std::endl;
	else
		std::cout << "The robotomization of " << this->_target << " failed" << std::endl;
}