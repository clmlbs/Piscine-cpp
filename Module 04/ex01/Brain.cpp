/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:39:46 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain assignement operator called" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
		this->_ideas[i] = rhs._ideas[i];
    return *this;
}

void	Brain::setIdea(const std::string idea, int index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

const std::string&	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return this->_ideas[0];
}