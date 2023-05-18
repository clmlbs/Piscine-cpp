/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:53:09 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _Weapon(NULL)
{
	;
}

HumanB::~HumanB(void)
{
	;
}
		
void	HumanB::attack(void)
{
	if (!this->_Weapon)
		std::cout << this->_name << " attacks without weapon" << std::endl;
	else
	{
		std::cout << this->_name << " attacks with their " << this->_Weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& HumanBWeapon)
{
	this->_Weapon = &HumanBWeapon;
}