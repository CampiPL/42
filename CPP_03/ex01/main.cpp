/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:37:19 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 19:44:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap ash("Ash");
    ScavTrap ash2(ash);

    ash.attack("the air");
    ash.takeDamage(10);
    ash.beRepaired(10);
    ash.guardGate();

    return 0;
}