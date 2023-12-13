/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:45:39 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 14:36:52 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) : type_("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &str) {
    std::cout << "Animal constructor called" << std::endl;
    type_ = str;
}

Animal::Animal(const Animal &animal) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    std::cout << "Animal assignation operator called" << std::endl;
    this->type_ = animal.type_;
    return (*this);
}

Animal::~Animal(void) { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound(void) const { std::cout << "Animal sound" << std::endl; }

std::string Animal::getType(void) const { return (type_); }