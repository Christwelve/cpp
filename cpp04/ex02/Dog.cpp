/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:00:43 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 08:53:55 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

#include "Brain.hpp"

Dog::Dog(void) : Animal("Dog"), brain_(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), brain_(new Brain(*dog.brain_)) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->Animal::operator=(dog);
    delete brain_;
    brain_ = new Brain(*dog.brain_);
    return (*this);
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete brain_;
}

void Dog::makeSound(void) const { std::cout << "Wuff" << std::endl; }