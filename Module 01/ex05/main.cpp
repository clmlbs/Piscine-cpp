/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:15:00 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int checks_args(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "*** Error: bad number of arguments ***" << std::endl;
		return (1);
	}
	std::string order = argv[1];
	if (order != "DEBUG" && order != "INFO" && order != "WARNING" && order != "ERROR")
	{
		std::cout << "*** Error: you should put one argument amoung these four: ***" << std::endl;
		std::cout << "DEBUG   INFO   WARNING   ERROR" << std::endl;
		return (1);
	}
	return (0);
}


int	main(int argc, char** argv)
{
	Harl	Vyhea;

	if (checks_args(argc, argv))
		return (1); 
	Vyhea.complain((std::string)argv[1]);
	
	return (0);
}