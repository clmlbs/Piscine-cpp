/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:28:39 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/19 12:28:40 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.hpp"
#include "max.hpp"
#include "swap.hpp"

int main(void)
{
    int aa = 5;
    int bb = 8;

    float cc = 6.8;
    float dd = 44.9;

    double e = 77.5;
    double f = 0.22; 

    swap(aa, bb);
    std::cout << "aa: " << aa << " bb: " << bb << std::endl;
    std::cout << min(cc, dd) << std::endl;
    std::cout << min(e, f) << std::endl;
    std::cout << max(cc, dd) << std::endl;
    std::cout << max(e, f) << std::endl;
 
    std::cout << "=== CODE EXAMPLE ===" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return (0);
}