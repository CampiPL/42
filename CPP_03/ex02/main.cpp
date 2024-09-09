/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:49:56 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 19:55:42 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap ash("Ash");
    FragTrap ash2(ash);

    ash.attack("the air");
    ash.takeDamage(10);
    ash.beRepaired(10);
    ash.highFive();

    return 0;
}