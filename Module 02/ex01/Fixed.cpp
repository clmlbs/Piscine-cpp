/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:46:27 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int const   Fixed::_nb_bits(8);

Fixed::Fixed(void) : _value_in_fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _value_in_fixed_point(integer << _nb_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const float float_nb) : _value_in_fixed_point(std::roundf(float_nb * (1 << _nb_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed&   Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_value_in_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->_value_in_fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return float(this->getRawBits()) /(1 << _nb_bits);
}

int Fixed::toInt(void) const
{
    return this->_value_in_fixed_point >> _nb_bits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& i)
{
	o << i.toFloat();
	return o;
}