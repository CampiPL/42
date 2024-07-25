/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:02:31 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 19:14:54 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::addContact(void)
{
    static int  i;
    this->contacts[i % 8].init();
    this->contacts[i % 8].setIndex(i % 8);
	std::cout << "Added new contact to phone book!" << std::endl;
	std::cout << std::endl;
    i++;
}

void    PhoneBook::printContacts(void) const
{
    std::cout << std::endl;
    for (size_t i = 0; i < 8; i++)
        this->contacts[i].view(i);
    std::cout << std::endl;
}

int     PhoneBook::readInput() const
{
    int     input = -1;
    bool    valid = false;
    do
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 7))
            valid = true;
		else
		{
            std::cin.clear();
            std::cout << "Invalid index - please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    PhoneBook::display(void) const
{
    int i = this->readInput();
    this->contacts[i].display();
}