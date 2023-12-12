/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:22:23 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 14:36:55 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
   public:
    ClapTrap();                         // Default Constructor
    ClapTrap(std::string name);         // Constructor
    ClapTrap(const ClapTrap &clapTrap);  // CopyConstructor
    ~ClapTrap();                        // Destructor

    ClapTrap &operator=(const ClapTrap &clapTrap);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   private:
    std::string name_;
    int hitPoints_;
    int energyPoints_;
    int attackDamage_;
};

#endif