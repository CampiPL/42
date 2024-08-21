/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:23:30 by jdepka            #+#    #+#             */
/*   Updated: 2024/08/21 18:55:56 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : fixedPointValue(n << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fixedPointValue(std::roundf(n * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed& Fixed::operator=( const Fixed &rhs )
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

int     Fixed::toInt(void) const
{
    return this->fixedPointValue >> fractionalBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return o;
}
