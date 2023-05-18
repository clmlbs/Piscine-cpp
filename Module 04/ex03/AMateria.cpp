/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:18:59 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
	;	
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	;	
}

AMateria::AMateria(const AMateria& src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
	;
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	this->_type = rhs._type;
	return *this;
}

const std::string&	AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "donald"; // faire le Icharacter
}