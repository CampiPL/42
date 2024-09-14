/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:56:15 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 20:56:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->type << " destructor called" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}