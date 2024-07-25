/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:56:51 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 18:32:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
    	Contact     contacts[8];
    	int         readInput(void) const;

	public:
    	PhoneBook();
    	~PhoneBook();
    	void    addContact(void);
    	void    printContacts(void) const;
    	void    display(void) const;
};

#endif