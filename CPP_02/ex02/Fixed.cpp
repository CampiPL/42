/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:03:15 by jdepka            #+#    #+#             */
/*   Updated: 2024/08/21 19:04:51 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : fixedPointValue(n << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : fixedPointValue(std::roundf(n * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if ( this != &rhs )
        this->fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

float   Fixed::toFloat(void) const
{
    return static_cast<float> (this->getRawBits()) / (1 << fractionalBits);
}

int     Fixed::toInt(void) const {
    return this->fixedPointValue >> fractionalBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}

bool    Fixed::operator>(const Fixed &rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<(const Fixed &rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=(const Fixed &rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==(const Fixed &rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed&   Fixed::operator++(void)
{
    ++this->fixedPointValue;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    tmp.fixedPointValue = this->fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--(void)
{
    --this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    tmp.fixedPointValue = this->fixedPointValue--;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}
