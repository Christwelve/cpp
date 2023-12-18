/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 07:54:07 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 18:34:16 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(void) : value_(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) this->value_ = fixed.getRawBits();
    return (*this);
}

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    this->value_ = value << this->fraction_;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    this->value_ = roundf(value * (1 << this->fraction_));
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return (this->value_); }

void Fixed::setRawBits(int const raw) { this->value_ = raw; }

float Fixed::toFloat(void) const {
    return ((float)this->value_ / (1 << this->fraction_));
}

int Fixed::toInt(void) const { return (this->value_ >> this->fraction_); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}
