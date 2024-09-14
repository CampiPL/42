/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:17:43 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:18:15 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain   *brain;

    public:
        Cat(void);
        ~Cat(void);

    Cat(const Cat& src);
    Cat& operator=(const Cat& src);

    void   makeSound(void) const;
};

#endif