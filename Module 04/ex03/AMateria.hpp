/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:10:22 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream> 

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		virtual ~AMateria(void);
	
		AMateria& operator=(const AMateria& rhs);
		
		const std::string& 	getType() const;
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);
		
	protected:
		std::string	_type;
};	

#endif