/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:22:32 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;
	
	std::cout << "The address of the string is:		" << &str << std::endl;
	std::cout << "The address stocked in stringPTR is:	" << stringPTR << std::endl;
	std::cout << "The address stocked in stringREF is:	" << &stringREF << std::endl;
	
	std::cout << "The string is:				" << str << std::endl;
	std::cout << "The value pointed by stringPTR is:	" << *stringPTR << std::endl;
	std::cout << "The value pointed by stringREF is:	" << stringREF << std::endl;
	
	return (0);
}