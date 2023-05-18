/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:57:46 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& src) : AMateria(src) {}

Cure::~Cure(void) {}

Cure& Cure::operator=(const Cure& rhs)
{
	return *this;
}

AMateria* Cure::clone(void) const
{
	AMateria* clone = new Cure(*this);
	return clone;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}