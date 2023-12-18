/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:58:49 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 16:44:14 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed) this->value_ = fixed.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const {
    return (this->value_ > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
    return (this->value_ < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return (this->value_ >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return (this->value_ <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
    return (this->value_ == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return (this->value_ != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++() {
    this->value_++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->value_++;
    return (tmp);
}

Fixed &Fixed::operator--() {
    this->value_--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->value_--;
    return (tmp);
}
