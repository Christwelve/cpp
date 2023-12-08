/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:54:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:40:51 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) { return; }

Weapon::~Weapon(void) { return; }

const std::string& Weapon::getType() const { return (type_); }

void Weapon::setType(std::string type) { type_ = type; }