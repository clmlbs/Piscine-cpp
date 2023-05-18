/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:19:58 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/17 17:59:21 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base* 	generate(void)
{
	Base *base_ptr;
	
	int nb = rand() % 3;
	if (nb == 0)
		base_ptr = new A;
	else if (nb == 1)
		base_ptr = new B;
	else
		base_ptr = new C;
	return base_ptr;
}

void 	identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "It's a A type base" << std::endl;
	else if (b)
		std::cout << "It's a B type base" << std::endl;
	else if (c)
		std::cout << "It's a C type base" << std::endl;
	else
		std::cout << "Error: it's none of the 3 types" << std::endl;
		
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "It's a A type base" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "It's a B type base" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "It's a C type base" << std::endl;
		return ;
	}
	catch (std::exception &e) 
	{
		std::cout << "Error: it's none of the 3 types" << std::endl;
	}
	
}

int main(void)
{
	std::srand(time(0));

	Base *base_ptr = generate();
	identify(base_ptr);
	identify(*base_ptr);

	return (0);
}