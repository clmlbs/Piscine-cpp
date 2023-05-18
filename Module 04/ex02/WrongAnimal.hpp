/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:50 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 19:20:50 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& src);
        ~WrongAnimal(void);
        WrongAnimal& operator=(const WrongAnimal& rhs);

        const std::string&	getType(void) const;
        void        makeSound(void) const;

    protected:
        std::string _type;
        
};

#endif 