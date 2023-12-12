/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:07:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 19:30:25 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &skavTrap) { *this = skavTrap; }

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

//========================== Operator Overloading =================================

ScavTrap &ScavTrap::operator=(const ScavTrap &skavTrap) {
    this->setName(skavTrap.getName());
    this->setHitPoints(skavTrap.getHitPoints());
    this->setEnergyPoints(skavTrap.getEnergyPoints());
    this->setAttackDamage(skavTrap.getAttackDamage());
    return (*this);
}

//========================== Memberfunctions ==========================

void ScavTrap::attack(const std::string &target) {
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
              << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is in Gate keeper mode." << std::endl;
}