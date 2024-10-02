/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:45:45 by jdepka            #+#    #+#             */
/*   Updated: 2024/10/02 12:46:16 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    Converter c;

    try {
        c.setStr(argv[1]);
        c.convert();

        std::cout << c;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}