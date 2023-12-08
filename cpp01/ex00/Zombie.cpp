/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:21:43 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:41:42 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { return; }

Zombie::~Zombie(void) {
    std::cout << name_ << " destroyed" << std::endl;
    return;
}

void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) { name_ = name; }
