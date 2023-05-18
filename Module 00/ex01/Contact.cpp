/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:13:15 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_first_name(void) const
{
	return(this->_FirstName);
}

std::string Contact::get_last_name(void) const
{
	return(this->_LastName);
}

std::string	Contact::get_nickname(void) const
{
	return(this->_Nickname);
}

std::string Contact::get_phone_number(void) const
{
	return(this->_PhoneNumber);
}

std::string	Contact::get_secret(void) const
{
	return(this->_DarkestSecret);
}

void	Contact::set_first_name(std::string first_name)
{
	this->_FirstName = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_LastName = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_Nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_PhoneNumber = phone_number;
}

void	Contact::set_secret(std::string secret)
{
	this->_DarkestSecret = secret;
}