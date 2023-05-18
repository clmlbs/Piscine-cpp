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

Dog::Dog(void) : AAnimal("Dog"), _Brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : AAnimal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
	this->_Brain = new Brain(*src._Brain);
    *this = src;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
	delete this->_Brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog assignement operator called" << std::endl;
	AAnimal::operator=(rhs);
    return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "Dog sound: Woooouf" << std::endl;
}

Brain&	Dog::getBrain(void) const
{
	return *this->_Brain;
}