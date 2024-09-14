/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:20:11 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:21:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << this->type << " constructor called" << std::endl;
    try {
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Dog::~Dog(void)
{
    delete  this->brain;
    std::cout << this->type << " destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}

Dog::Dog(const Dog& src)
{
    *this = src;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "<Dog.cpp:32> Dog copy called." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}
