/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:31:26 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/14 21:32:54 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain created." << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain(const Brain& src)
{
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    std::cout << "<Brain.cpp:32> Brain copy called." << std::endl;
    if (this != &src)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    return *this;
}
