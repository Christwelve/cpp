/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:10:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 08:53:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->Animal::operator=(cat);
    return (*this);
}

Cat::~Cat(void) { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound(void) const { std::cout << "Meow" << std::endl; }