/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:31:04 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Empty;
	ScavTrap Riri("Riri");
	ScavTrap Init("Fifi");
	ScavTrap Fifi(Init);
	ClapTrap Daisy("Daisy");

	Riri.attack("Donald");
	Riri.attack("Dingo");
	Daisy.attack("Mickey");
	Riri.takeDamage(7);
	Riri.guardGate();
	Fifi.takeDamage(9);
	Fifi.beRepaired(10);
	Fifi.takeDamage(250);
	Fifi.attack("Donald");
	return (0);
}