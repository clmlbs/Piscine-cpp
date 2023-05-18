/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:59 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap from " << name << " constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl; 
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap from " << this->_name << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	ClapTrap::operator=(rhs);
	return *this;	
}

void	FragTrap::highFivesGuys(void)
{
	std::string field;

	std::cout << "To let's continue this superb game you should enter \"HIGH FIVE\" or \"BIG HAND\" to continue" << std::endl;
	while (1)
	{	
		std::getline(std::cin, field);
		if (std::cin.eof())
				exit(1);
		if (field[0] && (field == "HIGH FIVE" || field == "BIG HAND"))
		{
			std::cout << "You're nice to FragTrap from " << this->_name << " thanks for him!" << std::endl;
			break ;
		}
		else if (field[0])
		{
			std::cout << "*** You should enter \"HIGH FIVE\" or \"BIG HAND\"***" << std::endl;
		}
		else
			std::cout << "*** The field cannot be empty, enter \"HIGH FIVE\" or \"BIG HAND\"***" << std::endl;
	}
}
