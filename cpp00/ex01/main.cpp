/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:54:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/17 17:44:44 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string cmd;

    try {
        while (1) {
            cmd = phoneBook.get_input("Enter a command (ADD, SEARCH, EXIT): ");

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
    } catch (std::exception &e) {
        std::cout << "Phonebook closed" << std::endl;
    }

    return (0);
}
