/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:42:47 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 18:54:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iomanip>

PhoneBook::PhoneBook() : index_(0), maxIndex_(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_input(const std::string prompt) {
    std::string input;
    while (1) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "Phonebook closed" << std::endl;
            exit(0);
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
    maxIndex_ = index_ >= MAX_CONTACTS ? MAX_CONTACTS - 1 : index_;
}

void PhoneBook::displayContacts() {
    if (index_ < 1) {
        std::cout << "No contacts" << std::endl;
        return;
    }
    for (size_t i = 0; i < maxIndex_; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contacts_[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(contacts_[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(contacts_[i].getNickname()) << std::endl;
    }

    std::string input;
    input = get_input("Enter an index: ");
    size_t i;
    try {
        i = std::stoi(input);
    } catch (const std::exception& e) {
        std::cout << "Invalid Input" << std::endl;
        return;
    }
    if (i >= maxIndex_) {
        std::cout << "No Contact" << std::endl;
        return;
    }

    std::cout << contacts_[i].getFirstName() << std::endl;
    std::cout << contacts_[i].getLastName() << std::endl;
    std::cout << contacts_[i].getNickname() << std::endl;
    std::cout << contacts_[i].getPhoneNumber() << std::endl;
    std::cout << contacts_[i].getDarkestSecret() << std::endl;
}