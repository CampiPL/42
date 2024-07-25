/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:06:29 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 19:16:32 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void) {
    PhoneBook	book;
    std::string	input;

	input = "";
	std::cout << std::endl;
    std::cout << "Type one of three options:" << std::endl;
	std::cout << std::endl;
    std::cout << "ADD: save a new contact" << std::endl;
    std::cout << "SEARCH: display a specific contact" << std::endl;
    std::cout << "EXIT: quit the program." << std::endl;
    while (input.compare("EXIT"))
	{
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0)
		{
            book.printContacts();
            book.display();
        }
        std::cout << "> " << std::flush;
		std::cin >> input;
    }
    return 0;
}