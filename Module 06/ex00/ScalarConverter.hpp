/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:12:26 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/17 17:12:26 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <climits>
#include <limits>
#include "Exception.hpp"
#include <iomanip>
#include <string>
#include <cmath>
#include <cfloat>

class ScalarConverter
{
    public:
        static void Convert(const std::string nb_w);
    private:
        ScalarConverter(void) {}
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter(void) {}
};

