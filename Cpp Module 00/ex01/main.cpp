/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:24:22 by aychikhi          #+#    #+#             */
/*   Updated: 2025/07/04 17:46:55 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int main() {
    std::string command;
    
    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";

    // Get what the user types
    std::cin >> command;

    // Just repeat what they said for now
    std::cout << "You said: " << command << std::endl;
    
    return 0;
}

 