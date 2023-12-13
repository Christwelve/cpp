/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:10:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 12:58:18 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat"), brain_(new Brain()) {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), brain_(new Brain(*cat.brain_)) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat assignation operator called" << std::endl;
    this->Animal::operator=(cat);
    delete brain_;
    brain_ = new Brain(*cat.brain_);
    return (*this);
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete brain_;
}

void Cat::makeSound(void) const { std::cout << "Meow" << std::endl; }