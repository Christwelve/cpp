/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 07:54:07 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 18:35:40 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed(void) : value_(0) {}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::Fixed(int const value) { this->value_ = value << this->fraction_; }

Fixed::Fixed(float const value) { this->value_ = roundf(value * (1 << this->fraction_)); }

Fixed::~Fixed(void) {}

// Min/Max-----------------------------------------------------------------//

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b ? a : b); }

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b ? a : b); }

// Utils-----------------------------------------------------------------//

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
