/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:54:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 18:58:05 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string cmd;

    while (1) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD" || cmd == "add") {
            phoneBook.addContact();
        } else if (cmd == "SEARCH" || cmd == "search") {
            phoneBook.displayContacts();
        } else if (cmd == "EXIT" || cmd == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT."
                      << std::endl;
        }
    }
    return (0);
}