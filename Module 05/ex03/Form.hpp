/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:04:25 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/14 19:04:27 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	public:
		virtual ~Form(void);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getIfSigned(void) const;
		void				beSigned(const Bureaucrat& employee);
		int					modifyGrade(int grade) const;
		void				execute(Bureaucrat const& executor) const;
		virtual void		action(void) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: the grade is too high. Grades possibles [1 - 150]");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: the grade is too low. Grades possibles [1 - 150]");
				}	
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: the form is not signed");
				}
		};

	protected:
		Form(void);
		Form(const std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& src);
		Form& operator=(const Form& rhs);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
};

std::ostream& operator<<(std::ostream& ofs, const Form& rhs);

#endif