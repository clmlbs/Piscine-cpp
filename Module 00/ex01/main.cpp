/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:17:44 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

void	ft_add(PhoneBook &Repertory, int &index, int &index_max)
{
	Contact			Person;
	std::string		field;
	
	while (1)
	{
		std::cout << "Enter the first name of the new contact: ";
		std::getline(std::cin, field);
		if (std::cin.eof())
				exit(1);
		if (field[0])
		{
			Person.set_first_name(field);
			break ;
		}
		else
			std::cout << "*** The field cannot be empty, enter a first name ***" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter the last name of the new contact: ";
		std::getline(std::cin, field);
		if (std::cin.eof())
				exit(1);
		if (field[0])
		{
			Person.set_last_name(field);
			break ;
		}
		else
			std::cout << "*** The field cannot be empty, enter a last name ***" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter the nickname of the new contact: ";
		std::getline(std::cin, field);
		if (std::cin.eof())
				exit(1);
		if (field[0])
		{
			Person.set_nickname(field);
			break ;
		}
		else
			std::cout << "*** The field cannot be empty, enter a nickname ***" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter the phone number of the new contact: ";
		std::getline(std::cin, field);
		if (std::cin.eof())
				exit(1);
		if (ft_isdigit(field) && field[0])
		{
			Person.set_phone_number(field);
			break ;
		}
		else if (!field[0])
			std::cout << "*** The field cannot be empty, enter a phone number ***" << std::endl;
		else
			std::cout << "*** Unvalid phone number, you should enter only digits ***" << std::endl;

	}
	while (1)
	{
		std::cout << "Enter the darkest secret of the new contact: ";
		std::getline(std::cin, field);
		if (std::cin.eof())
				exit(1);
		if (field[0])
		{
			Person.set_secret(field);
			break ;
		}
		else
			std::cout << "*** The field cannot be empty, enter the darkest secret ***" << std::endl;
	}
	Repertory.set_contact(Person, index);
	if (index == 7)
	{
		index = 0;
		index_max = 8;
	}
	else if (index_max < 8)
	{
		index++;
		index_max++;
	}
	else
		index++;
}

void	ft_search(PhoneBook &Repertory, int &index_max)
{
	Contact		Person;
	std::string	index_str;
	
	std::cout << std::setfill('-');
	std::cout << "~" << std::setw(44) << "~" << std::endl;
	std::cout << std::setfill(' ');
	ft_put_line("Index", "First name", "Lastname", "Nickname");
	for (int i = 0 ; i < index_max ; i++)
	{
		index_str = std::to_string(i + 1);
		Person = Repertory.get_contact(i);
		ft_put_line(index_str, Person.get_first_name(), Person.get_last_name(), \
			Person.get_nickname());	
	}
	std::cout << std::setfill('-');
	std::cout << "~" << std::setw(44) << "~" << std::endl;
	std::cout << std::setfill(' ');
	enter_index(Repertory, Person, index_str, index_max);
}

int	main(int argc, char **argv)
{
	PhoneBook	Repertory;
	std::string	command;
	int			index(0);
	int			index_max(0);
	
	while (1)
	{
		std::cout << std::endl;
		std::cout << "===== You can enter one of the three commands below =====" << std::endl;
		std::cout << "ADD	save a new contact" << std::endl;
		std::cout << "SEARCH	display a specific contact" << std::endl;
		std::cout << "EXIT	quit and suppress all contacts" << std::endl << std::endl;
		std::cout << "Enter the command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
				exit(1);
		if (command.compare("ADD") == 0)
			ft_add(Repertory, index, index_max);
		else if (command.compare("SEARCH") == 0)
		{
			if (index_max >= 1)
				ft_search(Repertory, index_max);
			else 
				std::cout << "***** The repertory is empty you should at least add one contact first *****" << std::endl;
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << std::endl << "***** Unvalid command, retry *****" << std::endl;
	}
	return (0);
}