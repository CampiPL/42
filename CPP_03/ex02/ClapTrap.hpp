/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:50:12 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/09 19:56:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string     name;
        unsigned int    hitPoints;
        unsigned int    energyPoints;
        unsigned int    attackDamage;

        ClapTrap();

    public:
        ClapTrap(std::string name);
        ~ClapTrap();

        ClapTrap(const ClapTrap &);
        ClapTrap&       operator=(const ClapTrap& rhs);

        void            attack(std::string const& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);

};

#endif