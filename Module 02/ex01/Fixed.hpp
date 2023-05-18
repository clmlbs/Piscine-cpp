/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:31:42 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed // test couleur
{
    public:
        Fixed(void);
        Fixed(const Fixed& src);
        Fixed(const int integer);
        Fixed(const float float_nb);
        ~Fixed(void);

        Fixed&  operator=(const Fixed& rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        int                 _value_in_fixed_point;
        static int const    _nb_bits;
};

std::ostream&   operator<<(std::ostream& o, const Fixed& i);

#endif