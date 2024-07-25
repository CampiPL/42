/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:55:40 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 18:40:40 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
	    std::string firstName;
	    std::string lastName;
		std::string nickname;
	    std::string phoneNumber;
		std::string darkestSecret;
	    int         index;
	
	    std::string printLen(std::string str) const;
	    std::string getInput(std::string str) const;
	
	public:
	    Contact();
	    ~Contact();
	    void    init(void);
		void    setIndex(int i);
	    void    view(int index) const;
	    void    display() const;
};

#endif