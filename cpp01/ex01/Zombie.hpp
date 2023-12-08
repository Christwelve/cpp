/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:22:17 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:41:03 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
   private:
    std::string name_;

   public:
    Zombie(void);
    ~Zombie(void);
    void announce(void);
    void set_name(std::string name);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);
#endif
