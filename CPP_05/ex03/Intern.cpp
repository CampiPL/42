/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:20:13 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 12:20:48 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
    *this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs)
{
    (void) rhs;
    return (*this);
}

Form*   Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    Form*    forms[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)
    };
    
    for (int i(0); i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i];
        }
    }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return nullptr;
}