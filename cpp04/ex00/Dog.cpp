/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:00:43 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/20 12:08:07 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->Animal::operator=(dog);
    return (*this);
}

Dog::~Dog(void) { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound(void) const { std::cout << "Wuff" << std::endl; }