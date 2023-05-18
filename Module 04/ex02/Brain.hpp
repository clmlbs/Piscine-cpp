/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:32:28 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& src);
		~Brain(void);

		Brain&	operator=(const Brain& rhs);

		void				setIdea(const std::string idea, int index);
		const std::string&	getIdea(int index) const;
		
	private: 
		std::string _ideas[100];
};

#endif