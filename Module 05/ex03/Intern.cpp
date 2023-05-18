/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:30:47 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:52:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern &rhs)
{
	return *this;
}

Intern::~Intern(void) {}

Form* Intern::makeForm(std::string name, const std::string target)
{
	std::string	forms[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	for (int i = 0 ; i < 3 ; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << "Form" << std::endl;
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	std::cout << "Error: This form doesn't exist" << std::endl;
	return NULL;
}