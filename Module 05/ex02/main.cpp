/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:32 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:52:57 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(0));
	try
	{
		Bureaucrat Chief("Chief", 1);
		std::cout << "\n ====== INIT =====\n";
		std::cout << Chief << std::endl;

		Bureaucrat TheWorst("TheWorst", 150);
		std::cout << TheWorst << std::endl;

		ShrubberyCreationForm *Shrubbery = new ShrubberyCreationForm("garden");
		std::cout << *Shrubbery << std::endl;

		std::cout << "\n=== Error: not signed ===" << std::endl;
		Chief.executeForm(*Shrubbery);

		std::cout << "\n=== Works normally ===" << std::endl;
		Chief.signForm(*Shrubbery);
		std::cout << *Shrubbery << std::endl;
		
		std::cout << "\n=== Error of grade to execute ===" << std::endl;
		TheWorst.executeForm(*Shrubbery);

		std::cout << "\n=== Execute Shrubbery ===" << std::endl;
		Chief.executeForm(*Shrubbery);

		std::cout << "\n=== Execute Robotomy ===" << std::endl;
		RobotomyRequestForm *Robot = new RobotomyRequestForm("Human");
		std::cout << *Robot << std::endl;
		Chief.signForm(*Robot);
		for (int i = 0 ; i < 5 ; i++)
			Chief.executeForm(*Robot);

		std::cout << "\n=== Execute Presidential ===" << std::endl;
		PresidentialPardonForm *Vilain = new PresidentialPardonForm("Vilain");
		std::cout << *Vilain << std::endl;
		Chief.signForm(*Vilain);
		Chief.executeForm(*Vilain);

		delete Shrubbery;
		delete Robot;
		delete Vilain;

	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	//system("leaks form");
	return 0;
}