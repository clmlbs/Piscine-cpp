/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:11:57 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/17 17:11:57 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ExceptionEmptyString : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: nothing written");
		}
};

class ExceptionNotANumber : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: this is not a valid number");
		}
};

class ExceptionOutOfRange : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
    		return ("Error: the number is out of range");
		}
};