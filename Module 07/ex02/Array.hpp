/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:29:26 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/19 12:29:27 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& src);
        ~Array(void);

        Array& operator=(const Array& rhs);
        T& operator[](unsigned int n) const;
        unsigned int size(void) const;

    private:
        T*              _content;
        unsigned int    _size;

};