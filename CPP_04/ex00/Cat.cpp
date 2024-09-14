/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:49:18 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 20:49:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << this->type << " destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}