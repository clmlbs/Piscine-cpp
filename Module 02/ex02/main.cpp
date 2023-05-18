/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:45:34 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	Fixed const e(9.7f);

	std::cout << (Fixed::min(b, e)) << std::endl;
	std::cout << (Fixed::max(b, e)) << std::endl;

	Fixed c = 10;
	Fixed d = 5;
	
    std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "(c > d) = " <<(c > d) << std::endl;
	std::cout << "(c < d) = " << (c < d) << std::endl;
	std::cout << "(c - 5 >= d) = " << (c - 5 >= d) << std::endl;
	std::cout << "(c - 5 <= d) = " << (c - 5 <= d) << std::endl;
	std::cout << "(c == d) = " << (c == d) << std::endl;
	std::cout << "(c != d) = " << (c != d) << std::endl;
	
	std::cout << "(c + d) = " << (c + d) << std::endl;
	std::cout << "(c - d) = " << (c - d) << std::endl;
	std::cout << "(c * d) = " << (c * d) << std::endl;
	std::cout << "(c / d) = " << (c / d) << std::endl;
		
	return 0;
}