/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:27:59 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

std::string		repertory_format(std::string old);
void			display_full_info(Contact Person);
void			ft_put_line(std::string s1, std::string s2, std::string s3, std::string s4);
int				ft_isdigit(std::string str);
void			enter_index(PhoneBook &Repertory, Contact &Person, std::string index_str, int &index_max);


#endif