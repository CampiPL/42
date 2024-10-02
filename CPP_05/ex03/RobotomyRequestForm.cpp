/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:24:13 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 12:27:24 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : Form("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : Form(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
    (void)rhs;
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else
    {
        static int  i;
        if (i % 2 == 0)
            std::cout << "BZZZZZT! " << target << " has been robotomized!" << std::endl;
        else
            std::cout << "Robotomy failed! " << target << " is still alive." << std::endl;
        i++;
    }
}