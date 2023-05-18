/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:26:57 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

std::string	repertory_format(std::string old)
{
	int			rest;
	std::string	spaces("");
	std::string	str;
	
	if (old.length() > 10)
		str = old.substr(0,9) + ".";
	else
	{
		rest = 10 - old.length();
		for (int i = 0 ; i < rest ; i++)
			spaces = spaces + " ";
		str = spaces + old;
	}
	return (str);
}

void	display_full_info(Contact Person)
{
	std::cout << std::endl;
	std::cout << "============= CONTACT INFORMATIONS =============" << std::endl;
	std::cout << "First name:		" << Person.get_first_name() << std::endl;
	std::cout << "Last name:		" << Person.get_last_name() << std::endl;
	std::cout << "Nickname:		" << Person.get_nickname() << std::endl;
	std::cout << "Phone number:		" << Person.get_phone_number() << std::endl;
	std::cout << "Darkest secret:		" << Person.get_secret() << std::endl; 
}

void	ft_put_line(std::string s1, std::string s2, std::string s3, std::string s4)
{
	std::cout << std::right;
	std::cout << "|" ;
	std::cout << std::setw(10) << repertory_format(s1); 
	std::cout << "|"; 
	std::cout << std::setw(10) << repertory_format(s2);
	std::cout << "|";
	std::cout << std::setw(10) << repertory_format(s3); 
	std::cout << "|";
	std::cout << std::setw(10) << repertory_format(s4); 
	std::cout << "|";
	std::cout << std::endl;
}

int	ft_isdigit(std::string str)
{
	for (int i = 0 ; i < str.length() ; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

void	enter_index(PhoneBook &Repertory, Contact &Person, std::string index_str, int &index_max)
{
	while (1)
	{
		std::cout << std::endl << "Enter an index to display a contact's informations: ";
		std::getline(std::cin, index_str);
		if (std::cin.eof())
				exit(1);
		if (index_str[0] && ft_isdigit(index_str))
		{
			if (std::stoi(index_str) >= 1 && std::stoi(index_str) <= index_max)
			{
				Person = Repertory.get_contact(std::stoi(index_str) - 1);
				display_full_info(Person);
				break;
			}
			else
			{
				if (index_max == 1)
					std::cout << "*** Unvalid index, there is only one contact, enter 1" << std::endl;
				else
					std::cout << "*** Unvalid index, you should enter an index between 1 and " << index_max << " ***" << std::endl;
			}
		}
		else 
			std::cout << "*** Unvalid index, you should enter only digits ***" << std::endl;
	}
}