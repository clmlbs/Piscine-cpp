/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:23:52 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0 ; i < 8 ; i++)
	{
		this->_Friends[i].set_first_name("Empty");
		this->_Friends[i].set_last_name("Empty");
		this->_Friends[i].set_nickname("Empty");
		this->_Friends[i].set_phone_number("Empty");
		this->_Friends[i].set_secret("Empty");
	}
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::set_contact(Contact person, int index)
{
	this->_Friends[index] = person;
}

Contact	PhoneBook::get_contact(int index)
{
	Contact	Person;
	Person = this->_Friends[index];
	return (Person);
}