/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:44:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 12:51:26 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include "string"

HumanB::HumanB(std::string name) : name_(name) { return; }

HumanB::~HumanB(void) { return; }

void HumanB::setWeapon(Weapon &weapon) { weapon_ = &weapon; }

void HumanB::attack() {
    if (weapon_)
        std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
    else
        std::cout << name_ << " is unarmed" << std::endl;
}
