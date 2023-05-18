/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:54:12 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 17:58:55 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	int i = 0;
	try
	{
		Bureaucrat Chief("Chief", 1);
		std::cout << Chief << std::endl;
		
		Chief.levelDown();
		std::cout << Chief << std::endl;
		
		Chief.levelUp();
		std::cout << Chief << std::endl;

		Bureaucrat TheWorst("TheWorst", 150);
		std::cout << TheWorst << std::endl;

		std::cout << "== BUG LEVEL UP ===" << std::endl;
		Chief.levelUp();
		
		// std::cout << "== BUG LEVEL DOWN ===" << std::endl;
		// TheWorst.levelDown();

		// std::cout << "== BUG INIT ==" << std::endl;
		// Bureaucrat Neg("Neg", -7);

	}
	catch (std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	return 0;
}