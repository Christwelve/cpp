/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:22:17 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 16:14:05 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
   public:
    Zombie();
    ~Zombie();
    void announce(void);
    void set_name(std::string name);

   private:
    std::string name_;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
