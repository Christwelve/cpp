/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:36:28 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 17:54:13 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &ice) : AMateria(ice) {}

Ice &Ice::operator=(const Ice &ice) {
    AMateria::operator=(ice);
    return (*this);
}

Ice::~Ice() {}

std::string const &Ice::getType() const { return (AMateria::getType()); }

Ice *Ice::clone() const {
    Ice *ice = new Ice(*this);
    return (ice);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
