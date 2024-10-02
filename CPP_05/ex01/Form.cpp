/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:42:59 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 11:53:42 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign) : name(name), gradeToSign(gradeToSign), gradeToExecute(0)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : name(src.getName()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()) {}

Form::~Form() {}

Form&   Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        signd = rhs.getSigned();
    return *this;
}

std::string Form::getName() const
{
    return name;
}

bool   Form::getSigned() const
{
    return signd;
}

int   Form::getGradeToSign() const
{
    return gradeToSign;
}

int   Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    signd = true;
}

std::ostream&   operator<<(std::ostream& o, const Form& rhs)
{
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
    return o;
}