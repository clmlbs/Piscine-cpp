/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:21:58 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
public:
	Contact(void);
	~Contact(void);
	
	std::string		get_first_name(void) const;
	std::string		get_last_name(void) const;
	std::string		get_nickname(void) const;
	std::string		get_phone_number(void) const;
	std::string		get_secret(void) const;
	
	void	set_first_name(std::string first_name);
	void	set_last_name(std::string last_name);
	void	set_nickname(std::string nickname);
	void	set_phone_number(std::string phone_number);
	void	set_secret(std::string secret);
	
private:	
	std::string		_FirstName;
	std::string		_LastName;
	std::string		_Nickname;
	std::string		_PhoneNumber;
	std::string		_DarkestSecret;
};

#endif