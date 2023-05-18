/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:29:41 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define BIN_SIZE 2
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		
		Character(void);
		Character(std::string name);
		~Character(void);

		Character(const Character& src);
		Character& operator=(const Character& rhs);

		std::string const& 	getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		void				bin(AMateria *m);

	private:
		std::string _name;
		AMateria	*_inventory[4];
		AMateria	*_bin[BIN_SIZE];
};

#endif