/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:07:47 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 12:08:52 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    
        Bureaucrat();
    
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat();
    
        Bureaucrat  &operator=(const Bureaucrat& rhs);
    
        std::string getName() const;
        int         getGrade() const;
    
        void        incrementGrade();
        void        decrementGrade();
    
        void        signForm(Form& form);
    
        void        executeForm(const Form& form) const;  
    
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() {return "Grade too high";}
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() {return "Grade too low";}
        };

};

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif