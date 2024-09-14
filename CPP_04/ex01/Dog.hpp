/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:20:07 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:20:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain   *brain;

    public:
        Dog(void);
        ~Dog(void);

    Dog(const Dog& src);
    Dog& operator=(const Dog& src);

    void   makeSound(void) const;
};

#endif