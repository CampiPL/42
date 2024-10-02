/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:39:35 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 12:57:16 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(void)
{
    this->c = '\0';
    this->n = 0;
    this->f = 0.0f;
    this->d = 0.0;
}

Converter::Converter(const Converter& src)
{
    *this = src;
}

Converter::~Converter(void) {}

Converter& Converter::operator=(const Converter& rhs)
{
    if (this != &rhs)
    {
        this->n = rhs.getI();
        this->f = rhs.getF();
        this->c = rhs.getC();
    }
    return *this;
}

char    Converter::getC(void) const
{
    return this->c;
}

void    Converter::setC(char c)
{
    this->c = c;
}

bool    Converter::isLiterals(void) const
{
    if ((impossible) || (str.compare("nan") == 0) || (str.compare("nanf") == 0)
        || (str.compare("+inf") == 0 ) || (str.compare("+inff") == 0) 
        || (str.compare("-inf") == 0 ) || (str.compare("-inff") == 0) 
        || (str.compare("-inff") == 0 ) || (str.compare("-inff") == 0)  
        || (str.compare("+inff") == 0 ) || (str.compare("+inff") == 0))
        {
        return true;
    } 
    return false;
}

void    Converter::printChar(void) const
{
    if (this->isLiterals() || (!std::isprint(n) && (n >= 127)))
    {
        std::cout << "Impossible";
    }
    else if (!std::isprint(this->n))
    {
        std::cout << "None displayable";
    }
    else
    {
        std::cout << "'" << getC() << "'";
    }
    std::cout << std::endl;
}

int    Converter::getI(void) const
{
    return this->n;
}

void    Converter::setI(int n)
{
    this->n = n;
}

void    Converter::printInt(void) const
{
    if (this->isLiterals() || ( !std::isprint(n) && (n >= 127)))
    {
        std::cout << "Impossible";
    }
    else
    {
        std::cout << getI();
    }
    std::cout << std::endl;
}

float   Converter::getF(void) const
{
    return this->f;
}

void    Converter::setF(float f)
{
    this->f = f;
}

double  Converter::getD(void) const
{

    return this->d;
}

void    Converter::setD(double d)
{
    this->d = d;
}

std::string Converter::getStr(void) const
{
    return this->str;
}

void Converter::setStr(std::string str)
{
    this->str = str;
    this->setType();
    if (getType() == NONE)
    {
        throw Converter::ConverterException();
    }
}

e_type  Converter::getType(void) const
{
    return this->type;
}

bool    Converter::isChar(void) const
{
    return str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]);
}

bool    Converter::isInt(void) const
{
    int    j = 0;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i (j); i < (int) str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool Converter::isDouble(void) const
{

    if (str.find('.') == std::string::npos || str.find('.') == 0 
        || str.find('.') == str.length() - 1)
        return false;
    int j = 0;
    int found = 0;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i(j); i < (int) str.length(); i++ )
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || found > 1)
            return false;
    }
    return true;
}

bool    Converter::isFloat (void) const
{

    if (str.find('.') == std::string::npos || str.back() != 'f' 
        || str.find('.') == 0 || str.find('.') == str.length() - 2)
        return false;
    int found = 0;
    int j = 0;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i(j); i < (int) str.length() - 1; i++)
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || found > 1)
            return false;
    }

    return true;
}

void    Converter::printFloat(void) const
{
    if ( str.compare("nan") == 0 || str.compare("nanf") == 0)
    {
        std::cout << "nanf";
    }
    else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
    {
        std::cout << "+inff";
    }
    else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
    {
        std::cout << "-inff";
    }
    else if (impossible)
    {
        std::cout << "Impossible";
    }
    else
    {
        if (f - static_cast< int > (f) == 0)
        {
            std::cout << f << ".0f";
        } else
        {
            std::cout << getF() << "f";
        }
    }
    std::cout << std::endl;
}

void    Converter::printDouble(void) const
{
    if (str.compare("nan") == 0 || str.compare("nanf") == 0)
    {
        std::cout << "nan";
    }
    else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
    {
        std::cout << "+inf";
    }
    else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
    {
        std::cout << "-inf";
    }
    else if (impossible)
    {
        std::cout << "Impossible";
    }
    else
    {
        if (d - static_cast< int > (d) == 0)
        {
            std::cout << d << ".0";
        } 
        else 
        {
            std::cout << getD() << "f";
        }
    }
    std::cout << std::endl;
}

void    Converter::setType(void)
{
    if (isChar())
    {
        type = CHAR;
    }
    else if (isInt())
    {
        type = INT;
    }
    else if (isFloat())
    {
        type = FLOAT;
    }
    else if (isDouble())
    {
        type = DOUBLE;
    }
    else if (isLiterals())
    {
        type = LITERALS;
    }
    else
    {
        type = NONE;
    }
}

bool    Converter::isImpossible(void)
{
    try
    {
        if (type == INT)
        {
            n = std::stoi(str);
        }
        else if (type == FLOAT)
        {
            f = std::stof(str);
        }
        else if (type == DOUBLE)
        {
            d = std::stod(str);
        }
    }
    catch (std::exception& e)
    {
        impossible = true;
        return true;
    }
    return false;
}

void    Converter::convert(void)
{
    if (isImpossible())
        return;
    switch (type )
    {
    case CHAR:
        c = str[0];
        n = static_cast< int >(c);
        f = static_cast< float >(c);
        d = static_cast< double >(c);
        break;
    case INT:
        n = std::stoi(str);
        f = static_cast< float >(n);
        d = static_cast< double >(n);
        c = static_cast< char >(n);
        break;
    case FLOAT:
        f = std::stof(str);
        n = static_cast< int >(f);
        d = static_cast< double >(f);
        c = static_cast< char >(f);
        break;
    case DOUBLE:
        d = std::stod(str);
        n = static_cast< int >(d);
        f = static_cast< float >(d);
        c = static_cast< char >(d);
        break;
    default:
        break;
    }
}

std::ostream&    operator<<( std::ostream& out, const Converter& rhs )
{
    out << "char: "; rhs.printChar();
    out << "int: "; rhs.printInt();
    out << "float: "; rhs.printFloat();
    out << "double: "; rhs.printDouble();
    return out;
}
