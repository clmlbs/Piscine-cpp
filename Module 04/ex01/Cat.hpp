/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:09 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:09 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat& src);
        ~Cat(void);
        Cat& operator=(const Cat& rhs);

        void 	makeSound(void) const;
		Brain&	getBrain(void) const;
	private:
		Brain*	_Brain;
        
};

#endif 