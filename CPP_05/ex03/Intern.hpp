/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:19:48 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 12:20:05 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& src);
        ~Intern();
    
        Intern& operator=(const Intern& rhs);
    
        Form*   makeForm(std::string name, std::string target);
};

#endif