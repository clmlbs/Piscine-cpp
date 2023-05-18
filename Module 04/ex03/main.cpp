/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:53:33 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() 
{
	std::cout << "\n=== DEEP COPY ===" << std::endl;
	Cure 		*cure = new Cure();
	Ice			*ice = new Ice();
	Character	mickey("Mickey");
	ICharacter	*riri = new Character("riri");
	
	mickey.equip(cure);
	mickey.equip(ice);

	ICharacter	*donald = new Character(mickey);
	
	mickey.use(2, *riri);
	
	donald->use(0, *riri);
	donald->use(1, *riri);
	donald->use(2, *riri);
	donald->use(44, *riri);

	delete cure;
	delete ice;
	delete riri;
	delete donald;
	
	std::cout << "\n=== EQUIP AND UNEQUIP ===" << std::endl;
	donald = new Character("donald");
	riri = new Character("riri");
	cure = new Cure();
	ice = new Ice();
	
	donald->equip(cure);
	donald->equip(cure);
	donald->equip(ice);
	delete cure;

	donald->use(1, *riri); // Use is still functionning even if the original is deleted 
	
	donald->unequip(0);
	donald->unequip(1);
	donald->unequip(2);

	donald->unequip(2);
	donald->unequip(6);

	delete donald;
	delete ice;
	delete riri;

	std::cout << "\n=== NEW MATERIAS ===" << std::endl;
	donald = new Character("donald");
	riri = new Character("riri");
	IMateriaSource 	*object = new MateriaSource();
	AMateria		*iceberg;

	object->learnMateria(new Ice);
	iceberg = object->createMateria("ice");
	donald->equip(iceberg);
	donald->use(0, *riri);

	delete donald;
	delete riri;
	
	std::cout << "\n=== TESTS FROM SUBJECT ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	//system("leaks materia");//********
	return (0); 
}
