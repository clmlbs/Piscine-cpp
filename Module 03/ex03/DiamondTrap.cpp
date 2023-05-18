/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>> .            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:23 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/02 16:35:27 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
// {
//     std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
// 	this->_name = name;
// 	this->_hit_points = this->FragTrap::_hit_points;
// 	this->_energy_points = this->ScavTrap::_energy_points;
// 	this->_attack_damage = this->FragTrap::_attack_damage;
// //	this->ScavTrap::_name = name;
// }

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = this->FragTrap::_hit_points;
	this->_energy_points = this->ScavTrap::_energy_points;
	this->_attack_damage = this->FragTrap::_attack_damage;
	this->ClapTrap::_name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}
		
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy assignement constructor called" << std::endl;
	this->_name = rhs._name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return *this;
}
	
void	DiamondTrap::whoAmI(void)
{
	std::cout << "This DiamondTrap is called: " << this->_name;
	std::cout << " and his subobject is called: " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}