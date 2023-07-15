/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:11:51 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/17 17:11:51 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t integer = reinterpret_cast<uintptr_t>(ptr);
    return integer;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *data;
    data = reinterpret_cast<Data *>(raw);
	return data;
}

Serializer& Serializer::operator=(const Serializer& rhs) 
{
	(void)rhs;
	return *this;
}