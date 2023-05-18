/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:23:25 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
  public:
    ClapTrap(void);
	ClapTrap(std::string name);
    ClapTrap(const ClapTrap& src);
    ~ClapTrap(void);

	ClapTrap& operator=(const ClapTrap& rhs);
	
	void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount); 
	
  private:
    std::string     _name;
    unsigned int    _hit_points;
    unsigned int    _energy_points;
    unsigned int    _attack_damage;
};

#endif