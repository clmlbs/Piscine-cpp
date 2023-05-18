/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:25:03 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Riri("Riri");
	ClapTrap Fifi("Fifi");
	ClapTrap Loulou("Loulou");
	ClapTrap Copy(Loulou);

	Riri.attack("Donald");
	Riri.attack("Dingo");
	Riri.attack("Mickey");
	Riri.takeDamage(7);
	Fifi.takeDamage(9);
	Loulou.takeDamage(10);
	Fifi.beRepaired(10);
	Fifi.takeDamage(12);
	Fifi.takeDamage(50);
	Fifi.beRepaired(5);
	Fifi.attack("Donald");
	return (0);
}