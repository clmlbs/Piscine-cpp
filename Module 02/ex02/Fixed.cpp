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

Fixed::Fixed(void) : _value_in_fixed_point(0){;
}

Fixed::Fixed(const Fixed& src)
{
    *this = src;
}

Fixed::Fixed(const int integer) : _value_in_fixed_point(integer << _nb_bits) {;
}

Fixed::Fixed(const float float_nb) : _value_in_fixed_point(std::roundf(float_nb * (1 << _nb_bits))) {;
}

Fixed::~Fixed(void) {;
}

Fixed&   Fixed::operator=(const Fixed& rhs)
{
    this->setRawBits(rhs.getRawBits());
    return *this;
}

bool  Fixed::operator>(const Fixed& rhs) const
{
    if (this->_value_in_fixed_point > rhs.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator<(const Fixed& rhs) const
{
    if (this->_value_in_fixed_point < rhs.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator>=(const Fixed& rhs) const
{
    if (this->_value_in_fixed_point >= rhs.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator<=(const Fixed& rhs) const
{
    if (this->_value_in_fixed_point <= rhs.getRawBits())
        return true;
    else
        return false;
}

bool  Fixed::operator==(const Fixed& rhs) const
{
    if (this->_value_in_fixed_point == rhs.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    if (this->_value_in_fixed_point != rhs.getRawBits())
        return true;
    else
        return false;
}

Fixed   Fixed::operator+(const Fixed& rhs) const 
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed& rhs) const 
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed &rhs) const 
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed &rhs) const 
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(void)
{
	this->_value_in_fixed_point++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	this->_value_in_fixed_point--;
	return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed Buf = *this;
	++*this;
	return Buf;
}

Fixed Fixed::operator--(int)
{
	Fixed Buf = *this;
	--*this;
	return Buf;
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

Fixed&   Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
}

const Fixed&    Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
}

std::ostream& operator<<(std::ostream& o, const Fixed& i)
{
	o << i.toFloat();
	return o;
}