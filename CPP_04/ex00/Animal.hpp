/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:46:53 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 20:48:20 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

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