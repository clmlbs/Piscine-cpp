/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:41 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:09:37 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void) : _target("default_target"), \
Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target), \
Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : \
_target(src._target), Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) 
{ 
	return *this; 
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::action(void) const
{
	std::cout << this->_target << " has been excused by Zaphod Beeblebrox" << std::endl;
}