/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:12:41 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/17 17:12:41 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.information = "Good information";
    data.value = 12;
    std::cout << "BEFORE = Info: " << data.information << " and value: " << data.value << std::endl;
    std::cout << "Adress de data :" << &data << std::endl;
    uintptr_t uint = Serializer::serialize(&data);
    std::cout << "uint: " << uint << std::endl;
    Data *ptr_data = Serializer::deserialize(uint);
    std::cout << "Adress pointee ptr_data :" << ptr_data << std::endl;
    std::cout << "AFTER = Info: " << ptr_data->information << " and value: " << ptr_data->value << std::endl;

    return (0);
}