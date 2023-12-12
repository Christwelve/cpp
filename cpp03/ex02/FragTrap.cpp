/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:33:54 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 19:51:40 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) { *this = fragTrap; }

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

//========================== Operator Overloading =================================

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    this->setName(fragTrap.getName());
    this->setHitPoints(fragTrap.getHitPoints());
    this->setEnergyPoints(fragTrap.getEnergyPoints());
    this->setAttackDamage(fragTrap.getAttackDamage());
    return (*this);
}

//========================== Memberfunction ==========================

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << getName() << " is giving a high five." << std::endl;
}