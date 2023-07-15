/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:29:30 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/19 12:29:31 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _content(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->_content = new T[n];
}

template <typename T>
Array<T>::~Array(void)
{
    if (this->_content)
    {
        delete [] this->_content;
        this->_content = NULL;
    }
}

template <typename T>
Array<T>::Array(const Array& src)
{
    if (src._size)
        this->_content = new T[src._size];
    else
        this->_content = NULL;
    *this = src;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    this->_size = rhs._size;
    for (unsigned int i = 0 ; i < this->_size ; i++)
        this->_content[i] = rhs._content[i];
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int n) const
{
    if (!this->_size || n > this->_size - 1)
        throw std::exception();
    return (this->_content[n]);
}

template<typename T>
unsigned int Array<T>::size(void) const
{
    return this->_size;
}