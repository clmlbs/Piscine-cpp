/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:03:20 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:03:22 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		this->_grade = 1;
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		this->_grade = 150;
	}
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string& Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const 
{
	return this->_grade;
}

void Bureaucrat::levelUp(void)
{
	if (Bureaucrat::getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::levelDown(void)
{
	if (Bureaucrat::getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getIfSigned() == true)
		std::cout << this->getName() << " couldn't sign " << \
		form.getName() << " because the form is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << this->getName() << " couldn't sign " << \
			form.getName() << " because the grade is too low" << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& rhs)
{
	ofs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return ofs;
}