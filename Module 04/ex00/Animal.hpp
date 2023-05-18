/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:14 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:14 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal& src);
        virtual ~Animal(void);
        Animal& operator=(const Animal& rhs);

        const std::string&	getType(void) const;
        virtual void        makeSound(void) const;

    protected:
        std::string _type;
        
};

#endif 