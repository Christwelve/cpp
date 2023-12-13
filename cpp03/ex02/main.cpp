/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:29:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 09:17:11 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    // ClapTrap clapTrap("Chris");
    // ScavTrap scavTrap("Gero");
    FragTrap fragTrap("Ole");

    // clapTrap.attack("Gero");
    // clapTrap.takeDamage(5);
    // clapTrap.beRepaired(4);

    // scavTrap.attack("Chris");
    // scavTrap.takeDamage(5);
    // scavTrap.beRepaired(3);
    // scavTrap.guardGate();

    fragTrap.attack("Gero");
    fragTrap.takeDamage(1);
    fragTrap.beRepaired(2);
    fragTrap.highFivesGuys();

    return (0);
}