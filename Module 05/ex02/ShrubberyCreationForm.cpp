/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:53 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:04:53 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("default_target"), \
Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), \
Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : \
_target(src._target), Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) 
{ 
	return *this; 
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::action(void) const
{
	std::string		file = this->_target + "_shrubbery";
	std::ofstream 	output_file("./" + file);
	for (int i = 0 ; i < 2 ; i++)
	{
		output_file << " \n	     $\n        $$$\n       $$$$$\n";
		output_file << "      $$$$$$$\n     $$$$$$$$$\n";
		output_file << "    $$$$$$$$$$$\n   $$$$$$$$$$$$$\n";
		output_file << "  $$$$$$$$$$$$$$$\n $$$$$$$$$$$$$$$$$\n";
		output_file << "         |\n         |\n         |\n\n ";
	}
	
}