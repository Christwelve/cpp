/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:29:56 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 17:52:53 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &cure) : AMateria(cure) {}

Cure &Cure::operator=(const Cure &cure) {
    AMateria::operator=(cure);
    return (*this);
}

Cure::~Cure() {}

std::string const &Cure::getType() const { return (AMateria::getType()); }

Cure *Cure::clone() const {
    Cure *cure = new Cure(*this);
    return (cure);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
