/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:29:11 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:32:52 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern(void);
		
		Form*	makeForm(std::string name, const std::string target);
	
};