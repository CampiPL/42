/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:43:06 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 11:52:13 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                signd;
        const int           gradeToSign;
        const int           gradeToExecute;
    
        Form();
    
    public:
        Form(const std::string& name, int gradeToSign);
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& src);
        ~Form();

    Form&   operator=(const Form& rhs);

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade too high";}
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() {return "Grade too low";}
    };
};

std::ostream&   operator<<(std::ostream& o, const Form& rhs);

#endif