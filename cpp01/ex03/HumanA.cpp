/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:15:27 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:49:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {
    return;
}

HumanA::~HumanA(void) { return; }

void HumanA::attack() {
    std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
