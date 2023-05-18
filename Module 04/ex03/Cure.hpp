/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:20:04 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);
	
		Cure& operator=(const Cure& rhs);
		
		AMateria* 		clone(void) const;
		void 			use(ICharacter& target);

};

#endif