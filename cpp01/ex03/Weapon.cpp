/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:54:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 05:22:26 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : m_type(type)
{
    return;
}

Weapon::~Weapon(void)
{
    return;
}

const std::string& Weapon::getType() const
{
    return (m_type);    
}

void Weapon::setType(std::string type)
{
    m_type = type;
}