/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais  <cleblais@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:12:55 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/04 16:12:55 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "======= INIT ======" << std::endl;
const AAnimal* Zoo[8];
for (int i = 0 ; i < 8 ; i += 2)
{
	std::cout << i << "] " << std::endl;
	Zoo[i] = new Cat();
	std::cout << i + 1 << "] " << std::endl;
	Zoo[i + 1] = new Dog();
}

std::cout << "\n======= TYPES ======" << std::endl;
std::cout << Zoo[4]->getType() << " " << std::endl;
std::cout << Zoo[5]->getType() << " " << std::endl;


Brain *randomCatBrain = &(Zoo[4]->getBrain());
randomCatBrain->setIdea("I want cuddles but not on the paws", 50);
Brain *randomDogBrain = &(Zoo[5]->getBrain());
randomDogBrain->setIdea("I wanna play outside", 50);

std::cout << "\n======= GET IDEAS =====" << std::endl;
std::cout << "Cat idea: " << randomCatBrain->getIdea(50) << std::endl;
std::cout << "Dog idea: " << randomDogBrain->getIdea(50) << std::endl;


std::cout  << "\n======= DESTRUCTORS =====" << std::endl;
for (int i = 0 ; i < 8 ; i++)
{
	std::cout << i << "] " << std::endl;
	delete Zoo[i];
}

//***********************************************************

std::cout  << "\n======= CAT CONSTRUCTOR =====" << std::endl;
Cat *felix = new Cat;
Cat *equal_felix = new Cat;

std::cout  << "\n======= COPY AND ASSIGNEMENT OPERATORS =====" << std::endl;
Cat *copy_felix = new Cat(*felix);
*equal_felix = *felix;

std::cout  << "\n======= CAT DESTRUCTOR =====" << std::endl;
delete felix;
delete copy_felix;
delete equal_felix;

//***********************************************************

std::cout  << "\n======= DOG CONSTRUCTOR =====" << std::endl;
Dog *brutus = new Dog;
Dog *equal_brutus = new Dog;

std::cout  << "\n======= COPY AND ASSIGNEMENT OPERATORS =====" << std::endl;
Dog *copy_brutus = new Dog(*brutus);
*equal_brutus = *brutus;

std::cout  << "\n======= DOG DESTRUCTOR =====" << std::endl;
delete brutus;
delete copy_brutus;
delete equal_brutus;

//system("leaks Animal");//**************
return 0;
}