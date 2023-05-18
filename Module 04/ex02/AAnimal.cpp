/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:17 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:17 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "Animal " << type << " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout << "Animal assignement operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void AAnimal::makeSound(void) const
{
    if (this->_type == "default")
		std::cout << "Default animal sound: RAAAAW" << std::endl;
	else 
		std::cout << "Default " << this->_type << " sound: RAAAAW" << std::endl;
}

const std::string& AAnimal::getType(void) const
{
    return this->_type;
}