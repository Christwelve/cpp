/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:24:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 08:53:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = cat;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->WrongAnimal::operator=(cat);
    return (*this);
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat destructor called" << std::endl; }

void WrongCat::makeSound(void) const { std::cout << "Wrong cat sound" << std::endl; }