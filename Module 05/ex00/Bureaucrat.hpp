/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:58:31 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				levelUp(void);
		void				levelDown(void);
		
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

	private:
		const std::string	_name;
		int					_grade;
	
};

std::ostream& operator<<(std::ostream& ofs, const Bureaucrat& rhs);

#endif