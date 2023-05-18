/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:41:59 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default")
{
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = NULL;
	for (int i = 0 ; i < BIN_SIZE ; i++)
		this->_bin[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0 ; i < 4 ; i++)
		this->_inventory[i] = NULL;
	for (int i = 0 ; i < BIN_SIZE ; i++)
		this->_bin[i] = NULL;
}

Character::~Character(void)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (int i = 0 ; i < BIN_SIZE ; i++)
	{
		if (this->_bin[i])
			delete this->_bin[i];
	}
}

Character::Character(const Character& src) : ICharacter(src)
{
	*this = src;
}

Character& Character::operator=(const Character& rhs)
{
	this->_name = rhs._name;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int i = 0 ; i < BIN_SIZE ; i++)
		this->_bin[i] = NULL;
	return *this;
}

std::string const& 	Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (m && this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			std::cout << "Materia " << this->_inventory[i]->getType() << " is equiped at index: " << i << std::endl;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Error: index: " << idx << " invalid to unequip" << std::endl;
	else if (!this->_inventory[idx])
		std::cout << "Error: there isn't materia to unequip at index :" << idx << std::endl;
	else 
	{
		std::cout << "Materia " << this->_inventory[idx]->getType() << " is successfully unequip at index: " << idx << std::endl;
		Character::bin(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
}
	
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Error: index: " << idx << " invalid to use" << std::endl;
	else if (!this->_inventory[idx])
		std::cout << "Error: there isn't materia to use at index :" << idx << std::endl;
	else
		this->_inventory[idx]->use(target);
}

void Character::bin(AMateria *m)
{
	for (int i = 0 ; i <= BIN_SIZE ; i++)
	{
		if (i == BIN_SIZE)
		{
			std::cout << "The bin is full, it needs to be emptied" << std::endl;
			for (int i = 0 ; i < BIN_SIZE ; i++)
			{
				if (this->_bin[i])
				{
					delete this->_bin[i];
					this->_bin[i] = NULL;
				}
			}
			std::cout << "Bin successfully emptied" << std::endl;
			i = 0;
		}
		if (this->_bin[i] == NULL)
		{
			this->_bin[i] = m;
			return ;
		}
	}
}