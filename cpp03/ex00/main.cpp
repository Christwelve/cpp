/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:29:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 16:52:58 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    // ClapTrap example();
    ClapTrap first("Chris");

    first.attack("Gero");
    first.takeDamage(3);
    first.beRepaired(4);
    return (0);
}