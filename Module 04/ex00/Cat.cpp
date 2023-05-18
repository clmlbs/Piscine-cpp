/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:12 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:12 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat assignement operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat sound: Meeeeow" << std::endl;
}