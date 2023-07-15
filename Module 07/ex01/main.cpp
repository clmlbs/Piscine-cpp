/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:29:19 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/19 15:09:31 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cctype>

void ft_toupper(char &c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 32;
    }
}

void plus_one(int &nb)
{
    nb += 1;
}

void add_last_name(std::string &name)
{
    name = name + "_DUCK";
}


int main(void)
{
    char            hello[] = "hello";
    int             value[] = {18, 5, 2023};
    std::string     names[] = {"Riri", "Fifi", "Loulou"};

    std::cout << "Before: " << hello << std::endl;
    iter<char, unsigned int, void>(hello, sizeof(hello), &ft_toupper);
    std::cout << "After: " << hello << std::endl;
    iter<int, unsigned int, void>(value, 3, &plus_one);
    for (int i = 0 ; i < 3 ; i++)
        std::cout << value[i] << std::endl;
    iter<std::string, unsigned int, void>(names, 3, &add_last_name);
    for (int i = 0 ; i < 3 ; i++)
        std::cout << names[i] << std::endl;
    return 0;
}