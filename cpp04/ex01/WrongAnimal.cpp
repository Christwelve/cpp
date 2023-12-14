/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:22:07 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 08:53:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &str) {
    std::cout << "WrongAnimal constructor called" << std::endl;
    type_ = str;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->type_ = animal.type_;
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const { std::cout << "WrongAnimal sound" << std::endl; }

std::string WrongAnimal::getType(void) const { return (type_); }