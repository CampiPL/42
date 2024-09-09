/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:16:38 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 20:16:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    this->name = name;
    this->ClapTrap::name = name + "_clap_name";
    
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 30;
    
    std::cout << "# DiamondTrap # - " << this->name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "# DiamondTrap # - " << this->name << " is dead." << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "I am a DiamondTrap named " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}