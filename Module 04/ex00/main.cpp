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
const Animal* meta = new Animal();
std::cout << std::endl;
const Animal* j = new Dog();
std::cout << std::endl;
const Animal* i = new Cat();
std::cout << std::endl;
const Animal* lion = new Animal("Lion");
std::cout << std::endl;
const Cat* felix = new Cat();
std::cout << std::endl;
const Cat* copy_felix = new Cat(*felix);
std::cout << std::endl;
const Dog* brutus = new Dog();
std::cout << std::endl;
const Dog* copy_brutus = new Dog(*brutus);
std::cout << std::endl;
const WrongAnimal* vilain = new WrongCat();

std::cout << "\n======= TYPES ======" << std::endl;
std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << lion->getType() << " " << std::endl;
std::cout << vilain->getType() << " " << std::endl;

std::cout << "\n======= SOUNDS =====" << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
lion->makeSound();
vilain->makeSound();

std::cout  << "\n======= DESTRUCTORS =====" << std::endl;
delete meta;
std::cout << std::endl;
delete j;
std::cout << std::endl;
delete i;
std::cout << std::endl;
delete lion;
std::cout << std::endl;
delete felix;
std::cout << std::endl;
delete copy_felix;
std::cout << std::endl;
delete brutus;
std::cout << std::endl;
delete copy_brutus;
std::cout << std::endl;
delete vilain;
return 0;
}