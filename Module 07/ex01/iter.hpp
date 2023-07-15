/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:29:15 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/19 12:29:16 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename S, typename F>
void    iter(T* adress, S tab_size, F (*function)(T&))
{
    for (S i = 0 ; i < tab_size ; i++)
    {
        function(adress[i]);
    }
}