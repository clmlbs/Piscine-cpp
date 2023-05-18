/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:13:14 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:14 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    public:
        virtual ~AAnimal(void);
        AAnimal& operator=(const AAnimal& rhs);

        const std::string&	getType(void) const;
		virtual Brain&		getBrain(void) const = 0;

		virtual void        makeSound(void) const = 0;

    protected:
		AAnimal(void);
        AAnimal(std::string type);
        AAnimal(const AAnimal& src);
        std::string _type;
        
};

#endif 