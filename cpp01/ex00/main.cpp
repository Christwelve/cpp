/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:19:21 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 16:23:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie *Zombie;

    Zombie = newZombie("HeapZombie");
    Zombie->announce();
    delete Zombie;
    randomChump("StackZombie");
    return (0);
}
