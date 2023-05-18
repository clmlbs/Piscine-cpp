/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:03:45 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:03:48 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat Chief("Chief", 1);
		std::cout << Chief << std::endl;

		Bureaucrat TheWorst("TheWorst", 150);
		std::cout << TheWorst << std::endl;

		Form *P45 = new Form("P45", 45, 45);
		std::cout << *P45 << std::endl;

		std::cout << "\n=== Works normally ===" << std::endl;
		Chief.signForm(*P45);
		std::cout << *P45 << std::endl;	

		std::cout << "\n=== Error already sign ===" << std::endl;
		Chief.signForm(*P45);

		// std::cout << "\n=== Error to low to sign ===" << std::endl;
		// TheWorst.signForm(*P45);

	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return 0;
}