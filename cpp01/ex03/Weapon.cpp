/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:54:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 16:15:10 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const { return (type_); }

void Weapon::setType(std::string type) { type_ = type; }