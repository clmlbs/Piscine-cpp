/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:58:20 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0 ; i < 4 ; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) : IMateriaSource(src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];	
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (rhs._materia[i])
			this->_materia[i] = rhs._materia[i]->clone();
		else
			this->_materia[i] = NULL;	
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* new_materia)
{
	int i;
	
	for (i = 0; i < 4 ; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = new_materia;
			std::cout << "New materia learned" << std::endl;
			return ;
		}
	}
	if (i == 4)
		std::cout << "There are already four materia learned, cannot add another one" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			std::cout << "New materia successfully created" << std::endl;
			return (this->_materia[i]->clone());
		}
	}
	return (0);
}