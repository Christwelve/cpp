/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:35:25 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 07:14:35 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
                 std::string phoneNumber, std::string darkestSecret) {
    this->firstName_ = firstName;
    this->lastName_ = lastName;
    this->nickname_ = nickname;
    this->phoneNumber_ = phoneNumber;
    this->darkestSecret_ = darkestSecret;
}
Contact::~Contact() {}

std::string Contact::getFirstName() { return this->firstName_; }
std::string Contact::getLastName() { return this->lastName_; }
std::string Contact::getNickname() { return this->nickname_; }
std::string Contact::getPhoneNumber() { return this->phoneNumber_; }
std::string Contact::getDarkestSecret() { return this->darkestSecret_; }
