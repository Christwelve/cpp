/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:43:00 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 07:10:30 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define MAX_CONTACTS 8

#include <iostream>

#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    ~PhoneBook();

    std::string get_input(const std::string prompt);
    std::string truncate(std::string str);
    void addContact();
    void displayContacts();

   private:
    Contact contacts_[8];
    size_t index_;
    size_t maxIndex_;
};

#endif