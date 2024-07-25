/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:03:35 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 19:15:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getInput(std::string str) const
{
    std::string input = "";
    bool        valid = false;

    do
    {
        std::cout << str <<std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else
		{
            std::cin.clear();
            std::cout << "Invalid input - please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void)
{
    std::cin.ignore();
	std::cout << std::endl;
    this->firstName = this->getInput("Please enter you first name: ");
    this->lastName = this->getInput("Please enter your last name: ");
	this->nickname = this->getInput("Please enter your nickname: ");
    this->phoneNumber = this->getInput("Please enter your phone number: ");
    this->darkestSecret = this->getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

void    Contact::setIndex(int i)
{
    this->index = i;
}

std::string Contact::printLen(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::view(int index) const
{
    if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->printLen(this->firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->printLen(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display() const
{
    if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "Index: " << this->index << std::endl;
    std::cout << "First Name: " << this->firstName << std::endl;
    std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
    std::cout << std::endl;
}