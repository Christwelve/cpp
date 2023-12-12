/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:29:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 19:27:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap clapTrap("Chris");
    ScavTrap scavTrap("Gero");

    clapTrap.attack("Gero");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(4);

    scavTrap.attack("Chris");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(3);
    scavTrap.guardGate();
    return (0);
}