/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:39:36 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 17:49:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "AMateria.hpp"

Character::Character(void) : name_("") {}

Character::Character(const std::string &str) : name_(str) {}

Character::Character(const Character &character) { *this = character; }

Character &Character::operator=(const Character &character) {
    if (this != &character) {
        name_ = character.name_;
        for (int i = 0; i < 4; i++) {
            materia_[i] = character.materia_[i];
        }
    }
    return (*this);
}

Character::~Character() {}

std::string const &Character::getName() const { return (name_); }

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (materia_[i] == NULL) {
            materia_[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        materia_[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && materia_[idx] != NULL) {
        materia_[idx]->use(target);
    }
}
