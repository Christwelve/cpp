/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:08:58 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 14:17:14 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(void) : type_("") {}

AMateria::AMateria(const std::string &type) : type_(type) {}

AMateria::AMateria(const AMateria &aMateria) { *this = aMateria; }

AMateria &AMateria::operator=(const AMateria &aMateria) {
    if (this != &aMateria) this->type_ = aMateria.type_;
    return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return (this->type_); }

void AMateria::use(ICharacter &target) { std::cout << target.getName() << std::endl; }
