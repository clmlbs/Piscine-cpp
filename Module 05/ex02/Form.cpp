/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:17 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:04:17 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _grade_to_sign(150), \
_grade_to_execute(150), _isSigned(false) {}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute) : \
_name(name), _grade_to_sign(Form::modifyGrade(grade_to_sign)), \
_grade_to_execute(Form::modifyGrade(grade_to_execute)), _isSigned(false) {}

Form::Form(const Form& src) : _name(src._name), \
_grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
    *this = src;
}

Form& Form::operator=(const Form& rhs)
{
    this->_isSigned = rhs._isSigned;
    return *this;
}

Form::~Form(void) {}

const std::string& Form::getName(void) const
{
	return this->_name;
}

int Form::getGradeToSign(void) const 
{
	return this->_grade_to_sign;
}

int Form::getGradeToExecute(void) const 
{
	return this->_grade_to_execute;
}

bool Form::getIfSigned(void) const 
{
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& employee)
{
	if (employee.getGrade() > this->getGradeToSign())
        throw (Form::GradeTooLowException());
    else
        this->_isSigned = true;
}

int Form::modifyGrade(int grade) const
{
    if (grade < 1)
    {
        throw(Form::GradeTooHighException());
        return 1;
    }
    if (grade > 150)
    {
        throw(Form::GradeTooLowException());
        return 150;
    }
    return grade;
}

void Form::execute(Bureaucrat const& executor) const
{
	if (this->getIfSigned() == false)
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	this->action();
}

std::ostream& operator<<(std::ostream& ofs, const Form& rhs)
{
    ofs << "Form " << rhs.getName();
    if (rhs.getIfSigned() == true)
        ofs << " is signed.";
    else
        ofs << " isn't signed.";
    ofs << " The minimum grade to sign it is: " << rhs.getGradeToSign();
    ofs << " and the minimum grade to execute it is: " << rhs.getGradeToExecute();
	return ofs;
}