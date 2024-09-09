/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:49:47 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 19:57:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "< ScavTrap > - " << this->name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "< ScavTrap > - " << this->name << " destructed." << std::endl;
}

void    ScavTrap::attack(std::string const& target)
{
    if ( this->energyPoints <= 0 )
    {
        std::cout << "< ScavTrap > - " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "< ScavTrap > - " << this->name << " attacks " << target << " at range, causing " << this->attackDamage << " points of damage !" << std::endl;
    this->energyPoints -= 1;
}

void    ScavTrap::guardGate()
{
    std::cout << "< ScavTrap > - " << this->name << " is now in Gate keeper mode." << std::endl;
}