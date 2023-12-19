/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:33:54 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/19 22:04:21 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap default Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
    *this = fragTrap;
    std::cout << "FragTrap CopyConstructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    name_ = fragTrap.name_;
    hitPoints_ = fragTrap.hitPoints_;
    energyPoints_ = fragTrap.energyPoints_;
    attackDamage_ = fragTrap.attackDamage_;
    std::cout << "FragTrap CopyAssigenmentConstructor called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called" << std::endl; }

//========================== Memberfunction ==========================

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name_ << " is giving a high five." << std::endl;
}