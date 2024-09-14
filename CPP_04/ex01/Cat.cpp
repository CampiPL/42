/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:17:47 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:19:45 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
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

Cat::~Cat(void)
{
    std::cout << this->type << " destructor called" << std::endl;
    delete  this->brain;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}

Cat::Cat(const Cat& src)
{
    *this = src;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "<Cat.cpp:32> Cat copy called." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return *this;
}
