/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:10 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 19:30:22 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_("Default_Player"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) { *this = clapTrap; }

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

//========================== Operator Overloading =================================

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    this->name_ = clapTrap.name_;
    this->hitPoints_ = clapTrap.hitPoints_;
    this->energyPoints_ = clapTrap.energyPoints_;
    this->attackDamage_ = clapTrap.attackDamage_;
    return (*this);
}

//========================== Memberfunctions ==========================

void ClapTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing "
              << this->attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount > 0) {
        std::cout << "ClapTrap " << this->name_ << " takes " << amount << " damage!"
                  << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    // if (this->hitPoints_ + amount > 10) amount = 10 - this->hitPoints_;
    std::cout << "ClapTrap " << this->name_ << " has recovered " << amount
              << " points of HP!" << std::endl;
}

//========================== Setters ==========================

void ClapTrap::setName(std::string name) { this->name_ = name; }

void ClapTrap::setHitPoints(int hitPoints) { this->hitPoints_ = hitPoints; }

void ClapTrap::setEnergyPoints(int energyPoints) { this->energyPoints_ = energyPoints; }

void ClapTrap::setAttackDamage(int attackDamage) { this->attackDamage_ = attackDamage; }

//========================== Getters ==========================

std::string ClapTrap::getName() const { return (this->name_); }

int ClapTrap::getHitPoints() const { return (this->hitPoints_); }

int ClapTrap::getEnergyPoints() const { return (this->energyPoints_); }

int ClapTrap::getAttackDamage() const { return (this->attackDamage_); }