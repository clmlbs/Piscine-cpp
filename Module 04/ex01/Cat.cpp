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

Cat::Cat(void) : Animal("Cat"), _Brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
	this->_Brain = new Brain(*src._Brain);
    *this = src;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
	delete this->_Brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "Cat assignement operator called" << std::endl;
    Animal::operator=(rhs);
    return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "Cat sound: Meeeeow" << std::endl;
}

Brain&	Cat::getBrain(void) const
{
	return *this->_Brain;
}