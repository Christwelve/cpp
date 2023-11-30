/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:44:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 05:24:27 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name)
{
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void HumanB::setWeapon(Weapon& weapon)
{
    m_weapon = &weapon;
}

void HumanB::attack()
{
    if (m_weapon)
        std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
    else
        std::cout << m_name << " is unarmed" << std::endl;    
}
