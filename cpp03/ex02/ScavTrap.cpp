/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:07:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/19 22:05:53 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap) {
    *this = scavTrap;
    std::cout << "ScavTrap CopyConstructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    name_ = scavTrap.name_;
    hitPoints_ = scavTrap.hitPoints_;
    energyPoints_ = scavTrap.energyPoints_;
    attackDamage_ = scavTrap.attackDamage_;
    std::cout << "ScavTrap CopyAssigenmentConstructor called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called" << std::endl; }

//========================== Memberfunctions ==========================

void ScavTrap::attack(const std::string &target) {
    if (hitPoints_ == 0) {
        std::cout << "ScavTrap " << name_ << " is dead!" << std::endl;
        return;
    }
    if (energyPoints_ == 0) {
        std::cout << "ScavTrap " << name_ << " has no energy!" << std::endl;
        return;
    }
    energyPoints_--;
    std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing "
              << attackDamage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name_ << " is in Gate keeper mode." << std::endl;
}