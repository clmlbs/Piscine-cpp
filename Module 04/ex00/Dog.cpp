/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:06 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:06 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog assignement operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog sound: Woooouf" << std::endl;
}
