/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:03 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:03 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(const Dog& src);
        ~Dog(void);
        Dog& operator=(const Dog& rhs);

        void makeSound(void) const;
		Brain&	getBrain(void) const;

	private:
		Brain*		_Brain;
        
};

#endif 