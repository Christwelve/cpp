/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:42:47 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/17 20:36:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : index_(0), maxIndex_(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_input(const std::string prompt) {
    std::string input;

    while (1) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "Phonebook closed" << std::endl;
            throw std::exception();
        }
        if (input.length() > 0) {
            return (input);
        }
    }
}

std::string PhoneBook::truncate(std::string str) {
    if (str.length() > 10) {
        str.resize(9);
        str.append(".");
    }
    return (str);
}

void PhoneBook::addContact() {
    std::string fn = get_input("First name: ");
    std::string ln = get_input("Last name: ");
    std::string nn = get_input("Nickname: ");
    std::string pn = get_input("Phone number: ");
    std::string ds = get_input("Darkest secret: ");

    contacts_[index_ % MAX_CONTACTS] = Contact(fn, ln, nn, pn, ds);
    index_++;
    maxIndex_ = index_ >= MAX_CONTACTS ? MAX_CONTACTS : index_;
}

void PhoneBook::displayContacts() {
    if (index_ < 1) {
        std::cout << "No contacts" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "index"
              << "|";
    std::cout << std::setw(10) << "f_name"
              << "|";
    std::cout << std::setw(10) << "l_name"
              << "|";
    std::cout << std::setw(10) << "n_name" << std::endl;

    for (size_t i = 0; i < maxIndex_; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contacts_[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(contacts_[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(contacts_[i].getNickname()) << std::endl;
    }

    std::string input;
    input = get_input("Enter an index: ");
    size_t i;

    std::istringstream iss(input);
    if (!(iss >> i)) {
        std::cout << "Invalid Input" << std::endl;
        return;
    }
    if (i >= maxIndex_) {
        std::cout << "No Contact" << std::endl;
        return;
    }

    std::cout << "f_name:\t" << contacts_[i].getFirstName() << std::endl;
    std::cout << "l_name:\t" << contacts_[i].getLastName() << std::endl;
    std::cout << "n_name:\t" << contacts_[i].getNickname() << std::endl;
    std::cout << "phone:\t" << contacts_[i].getPhoneNumber() << std::endl;
    std::cout << "secret:\t" << contacts_[i].getDarkestSecret() << std::endl;
}
