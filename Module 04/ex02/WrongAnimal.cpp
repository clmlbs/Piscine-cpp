/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:17 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:17 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("default")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal " << type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal assignement operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void WrongAnimal::makeSound(void) const
{
    if (this->_type == "default")
		std::cout << "Default WrongAnimal sound: SHHHRHHHCRAA" << std::endl;
	else 
		std::cout << "Default " << this->_type << " sound: SHHHRHHHCRAA" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
    return this->_type;
}