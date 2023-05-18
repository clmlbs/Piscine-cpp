/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:23:12 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;										
}

ClapTrap::ClapTrap(const ClapTrap& src) 
{
	*this = src;
	std::cout << "ClapTrap copy constructor called" << std::endl;	
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap copy assignement operator called" << std::endl;
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks ";
		std::cout << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is dead so he cannot attacks!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is really to tired to attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_hit_points > amount)
	{
		std::cout << "ClapTrap " << this->_name << " is attacked and loose ";
		std::cout << amount << " points of hit points" << std::endl;
		this->_hit_points -= amount;
	}
	else if (this->_hit_points > 0 && this->_hit_points <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " is attacked and loose ";
		std::cout << this->_hit_points << " points of hit points"; 
		this->_hit_points = 0;
		std::cout << ". ClapTrap " << this->_name << " is now dead" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is already dead, you cannot attack dead bodies!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " is repaired ";
		std::cout << "of " << amount << " points of hit points" << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
	else if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is dead so he cannot be repaired!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is really to tired to be repaired!" << std::endl;
	}
}

