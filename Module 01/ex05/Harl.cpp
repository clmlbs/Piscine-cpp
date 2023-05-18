/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:53 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	;
}

Harl::~Harl(void)
{
	;
}

void	Harl::complain(std::string level)
{
	std::string		words[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void			(Harl::*complain_type[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	
	for (int i = 0; i < 4; i++)
	{
		if (words[i] == level)
		{
			(this->*complain_type[i])();
			break;
		}
	}
}


void Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-";
	std::cout << "pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn't put enough bacon in my burger ! If you did,";
	std::cout << " I wouldn't be asking for more !" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I've been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}