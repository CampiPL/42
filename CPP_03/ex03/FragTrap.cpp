/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:17:56 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 20:17:57 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "| FragTrap | - " << this->name << " constructed." << std::endl;
    std::cout << ClapTrap::attackDamage << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "| FragTrap | - " << this->name << " destructed." << std::endl;
}

void    FragTrap::highFive(void)
{
    if (this->energyPoints <= 0)
    {
        std::cout << "| FragTrap | - " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "| FragTrap | - " << this->name << " high fives everybody." << std::endl;
    this->energyPoints -= 1;
}