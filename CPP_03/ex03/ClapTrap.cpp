/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:09:01 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 20:15:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "[ ClapTrap ] - " << this->name << " has been born." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "[ ClapTrap ] - " << this->name << " has been destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    *this = rhs;
    std::cout << "[ ClapTrap ] - " << this->name << " has been copied with copy constuctor." << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& rhs)
{
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
    std::cout << "[ ClapTrap ] - " << this->name << " has been copied with copy assignment operator." << std::endl;
    return *this;
}

void    ClapTrap::attack(std::string const& target)
{
    if (energyPoints <= 0)
    {
        std::cout << "[ ClapTrap ] - " << this->name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "[ ClapTrap ] - " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    energyPoints -= 1;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
    {
        std::cout << "[ ClapTrap ] - " << this->name << " is dead!" << std::endl;
        return;
    }
    std::cout << "[ ClapTrap ] - " << this->name << " takes " << amount << " damage!" << std::endl;
    hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= amount)
    {
        std::cout << "[ ClapTrap ] - " << this->name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "[ ClapTrap ] - " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
    energyPoints -= 1;
    hitPoints += amount;
}
