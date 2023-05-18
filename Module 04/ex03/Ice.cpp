/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:57:46 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/09 14:31:11 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src) {}

Ice::~Ice(void) {}

Ice& Ice::operator=(const Ice& rhs)
{
	return *this;
}

AMateria* Ice::clone(void) const
{
	AMateria* clone = new Ice(*this);
	return clone;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}