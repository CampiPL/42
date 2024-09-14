/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:29:04 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:29:57 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(std::string type);

    virtual ~AAnimal(void);

    AAnimal(const AAnimal& src);
    AAnimal& operator=(const AAnimal& rhs);

    virtual void    makeSound(void) const = 0;;
    std::string     getType(void) const; 
};

#endif