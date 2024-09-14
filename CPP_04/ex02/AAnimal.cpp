/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:30:09 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:30:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
    std::cout << this->type << " constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "AAnimal " << this->type << " constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout << "<AAnimal.cpp:35: AAnimal assignment operator called" << std::endl;
    if ( this != &rhs )
    {
        this->type = rhs.type;
    }
    return *this;
}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal makeSound called" << std::endl;
}

std::string    AAnimal::getType(void) const
{
    return this->type;
}