/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:41:55 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/10 13:50:40 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);

		MateriaSource& operator=(const MateriaSource& rhs);


		void learnMateria(AMateria*);
		AMateria* createMateria(const std::string& type);
	
	private:
		AMateria*	_materia[4];

};

#endif