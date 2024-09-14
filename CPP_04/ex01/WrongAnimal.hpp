/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:23:24 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:23:54 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        ~WrongAnimal(void);

    WrongAnimal(const WrongAnimal& src);
    WrongAnimal& operator=(const WrongAnimal& rhs);

    void            makeSound(void) const;
    std::string     getType(void) const; 
};

#endif