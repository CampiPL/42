/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:13:26 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:13:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(std::string type);

    virtual ~Animal(void);

    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);

    virtual void    makeSound(void) const;
    std::string     getType(void) const; 
};

#endif