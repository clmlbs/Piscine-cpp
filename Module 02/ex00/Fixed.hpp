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

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& src);
        ~Fixed(void);

        Fixed&  operator=(const Fixed& rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 _value_in_fixed_point;
        static int const    _nb_bits;
};

#endif