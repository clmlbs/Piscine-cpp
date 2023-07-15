/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:12:21 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/17 17:12:21 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#define FLOAT_TYPE 1
#define DOUBLE_TYPE 2
#define INT_TYPE 3
#define INVALID_TYPE 4

void    PrintAll(char *c, int *i, float *f, double *d, int nb_fract);
int     isPseudoLit(const std::string nb_w);
void    ConvertPseudoLit(const std::string nb_w);
void    ConvertFloat(const std::string nb_w, int nb_fract);
void    ConvertDouble(const std::string nb_w, int nb_fract);
void    ConvertInt(const std::string nb_w);
int     CheckFormat(const std::string nb_w, int *nb_fract);
void    ConvertChar(char c);

void ScalarConverter::Convert(const std::string nb_w)
{
    int format;
    int nb_fract;

    if (nb_w.size() == 0)
        throw(ExceptionEmptyString());
    else if (nb_w.size() == 1 && !std::isdigit(nb_w[0]))
        ConvertChar(static_cast<char>(nb_w[0]));
    else if (isPseudoLit(nb_w))
        ConvertPseudoLit(nb_w);
    else
    {
        format = CheckFormat(nb_w, &nb_fract);
        switch(format)
        {
            case FLOAT_TYPE:
                ConvertFloat(nb_w, nb_fract);
                break;
            case DOUBLE_TYPE:
                ConvertDouble(nb_w, nb_fract);
                break;
            case INT_TYPE:
                ConvertInt(nb_w);
                break;
            case INVALID_TYPE:
                throw(ExceptionNotANumber());
                break;
        }
    }
}

int CheckFormat(const std::string nb_w, int *nb_fract)
{
    int dot = 0, letter_f = 0, i = 0;
    *nb_fract = 0;
    if (nb_w[i] == '-' || nb_w[i] == '+')
        i++;
    while (nb_w[i])
    {
        if (nb_w[i] == '.')
            dot++;
        else if (nb_w[i] == 'f')
        {
            letter_f++;
            if (nb_w[i + 1])
                return (INVALID_TYPE);
        }
        else if (std::isdigit(nb_w[i]))
        {
            if (dot > 0)
                (*nb_fract)++;
        }
        else
            return (INVALID_TYPE);
        i++;
    }
    if (dot > 1 || letter_f > 1)
        return (INVALID_TYPE);
    if (dot && !(*nb_fract))
        return (INVALID_TYPE);
    if (letter_f && !dot)
        return (INVALID_TYPE);
    if (dot && letter_f)
        return (FLOAT_TYPE);
    if (dot)
        return (DOUBLE_TYPE);
    return (INT_TYPE);
}

void ConvertInt(const std::string nb_w)
{
    char *ptr_c ; char c ; int i; float f; double d; long long verif;
    ptr_c = &c;
    verif = std::stoll(nb_w);
    if (verif > INT_MAX || verif < INT_MIN)
        throw (ExceptionOutOfRange());
    i = std::stoi(nb_w);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    if (i < CHAR_MIN || i > CHAR_MAX)
        ptr_c = NULL;
    else 
        c = static_cast<char>(i);
    PrintAll(ptr_c, &i, &f, &d , 1);
}

void ConvertDouble(const std::string nb_w, int nb_fract)
{
    char *ptr_c ; char c ; int i; int *ptr_i ; float *ptr_f ; float f; double d;long double verif;
    ptr_c = &c; ptr_i = &i; ptr_f = &f;
    verif = std::stold(nb_w);
    if (verif > std::numeric_limits<double>::max() || verif < std::numeric_limits<double>::lowest())
        throw (ExceptionOutOfRange());
    d = std::stod(nb_w);
    if (d < CHAR_MIN || d > CHAR_MAX)
        ptr_c = NULL;
    else 
        c = static_cast<char>(std::round(d));
    if (d < INT_MIN || d > INT_MAX)
        ptr_i = NULL;
    else 
        i = static_cast<int>(std::round(d));
    if (d < std::numeric_limits<float>::lowest() || d > FLT_MAX)
        ptr_f = NULL;
    else 
        f = static_cast<float>(d);
    PrintAll(ptr_c, ptr_i, ptr_f, &d, nb_fract);
}

void ConvertFloat(const std::string nb_w, int nb_fract)
{
    char *ptr_c ; char c ; int i; int *ptr_i ; float f; double d; long double verif;
    ptr_c = &c; ptr_i = &i;
    verif = std::stold(nb_w);
    if (verif > FLT_MAX || verif < std::numeric_limits<float>::lowest())
        throw (ExceptionOutOfRange());
    f = std::stof(nb_w);
    d = static_cast<double>(f);
    if (f < CHAR_MIN || f > CHAR_MAX)
        ptr_c = NULL;
    else 
        c = static_cast<char>(std::round(f));
    if (f < INT_MIN || f > INT_MAX)
        ptr_i = NULL;
    else 
        i = static_cast<int>(std::round(f));
    PrintAll(ptr_c, ptr_i, &f, &d, nb_fract);
}

void ConvertChar(char c)
{
    int     i = static_cast<int>(c);
    float   f = static_cast<float>(c);
    double  d = static_cast<double>(c);
    PrintAll(&c, &i, &f, &d, 1);
}

int isPseudoLit(const std::string nb_w)
{
    if (nb_w == "-inff" || nb_w == "+inff" || nb_w == "nanf" || nb_w == "-inf" || \
    nb_w == "+inf" || nb_w == "nan")
        return (1);
    return (0);
}

void ConvertPseudoLit(const std::string nb_w)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (nb_w == "-inff" || nb_w == "inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (nb_w == "+inff" || nb_w == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (nb_w == "nanf" || nb_w == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void PrintAll(char *c, int *i, float *f, double *d, int nb_fract)
{
    if (!c)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(*c))
        std::cout << "char: Not dispensable" << std::endl;
    else
        std::cout << "char: '" << *c << "'" << std::endl;
    if (!i)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << *i << std::endl;
    if (!f)
        std::cout << "float: impossible" << std::endl;
    else
		std::cout << std::fixed << std::setprecision(nb_fract) << "float: " << *f << "f" << std::endl;
    if (!d)
        std::cout << "double: impossible" << std::endl;
    else   
        std::cout << std::fixed << std::setprecision(nb_fract) << "double: " << *d << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {*this = src;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) 
{ 
	(void)rhs;
	return *this;
}