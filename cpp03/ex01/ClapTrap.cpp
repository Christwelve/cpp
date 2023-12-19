/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:10 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/19 22:03:06 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_("Default_Player"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "ClapTrap default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;
    std::cout << "ClapTrap CopyConstructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    name_ = clapTrap.name_;
    hitPoints_ = clapTrap.hitPoints_;
    energyPoints_ = clapTrap.energyPoints_;
    attackDamage_ = clapTrap.attackDamage_;
    std::cout << "ClapTrap CopyAssigenmentConstructor called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called" << std::endl; }

//========================== Memberfunctions ==========================

void ClapTrap::attack(const std::string &target) {
    if (hitPoints_ == 0) {
        std::cout << "ClapTrap " << name_ << " is dead!" << std::endl;
        return;
    }
    if (energyPoints_ == 0) {
        std::cout << "ClapTrap " << name_ << " has no energy!" << std::endl;
        return;
    }
    energyPoints_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing "
              << attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints_ == 0) {
        std::cout << "ClapTrap " << name_ << " is dead!" << std::endl;
        return;
    }
    hitPoints_ = amount > hitPoints_ ? 0 : hitPoints_ - amount;
    std::cout << "ClapTrap " << name_ << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints_ == 0) {
        std::cout << "ClapTrap " << name_ << " is dead!" << std::endl;
        return;
    }
    if (energyPoints_ == 0) {
        std::cout << "ClapTrap " << name_ << " has no energy!" << std::endl;
        return;
    }
    energyPoints_--;
    std::cout << "ClapTrap " << name_ << " has recovered " << amount << " points of HP!"
              << std::endl;
}
