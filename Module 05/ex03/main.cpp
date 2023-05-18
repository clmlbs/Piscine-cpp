/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:32 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:53:21 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	srand(time(0));
	try
	{
		Bureaucrat Chief("Chief", 1);
		std::cout << Chief << std::endl;

		Bureaucrat TheWorst("TheWorst", 150);
		std::cout << TheWorst << std::endl;

		Intern Little;
		Form* form = Little.makeForm("NotExisting", "Human");
		form = Little.makeForm("RobotomyRequest", "Human");
		std::cout << *form << std::endl;
		Chief.signForm(*form);
		Chief.executeForm(*form);

		delete form;

	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	// system("leaks form");
	return 0;
}