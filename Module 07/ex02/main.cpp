/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:28:29 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/19 15:08:46 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main(void)
{
    try
    {
		Array <int>tab1;
        std::cout << "Size of tab1: " << tab1.size() << std::endl;
        // std::cout << tab1[7] << std::endl;

        Array <int>tab2(5);
        for (int i = 0 ; i < 5 ; i++)
            tab2[i] = i * 2;
        std::cout << "Size of tab2: " << tab2.size() << std::endl;
        for (int i = 0 ; i < 5 ; i++)
            std::cout << "tab2[" << i << "]: " << tab2[i] << std::endl;
        
        Array <std::string>tab3(3);
        for (int i = 0 ; i < 3 ; i++)
            tab3[i] = "repetitive";
        std::cout << "Size of tab3: " << tab3.size() << std::endl;
        for (int i = 0 ; i < 3 ; i++)
            std::cout << "tab3[" << i << "]: " << tab3[i] << std::endl;

        Array <int>tab4(tab2);
        for (int i = 0 ; i < 5 ; i++)
            tab2[i] = i * 5;
        for (int i = 0 ; i < 5 ; i++)
            std::cout << "tab2[" << i << "]: " << tab2[i] << std::endl;
        std::cout << "Size of tab4: " << tab4.size() << std::endl;
        for (int i = 0 ; i < 5 ; i++)
            std::cout << "tab4[" << i << "]: " << tab4[i] << std::endl;
	}
    catch(const std::exception& e)
    {
        std::cerr << "Error: Bad index" << std::endl;
    }
    return 0;
}