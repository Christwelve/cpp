/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:15:27 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 05:25:54 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name , Weapon& weapon) : m_name(name), m_weapon(weapon)
{   
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void HumanA::attack()
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}
