/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:22:23 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/19 21:36:01 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
   public:
    ClapTrap();                                     // Default Constructor
    ClapTrap(std::string name);                     // Constructor
    ClapTrap(const ClapTrap &clapTrap);             // CopyConstructor
    ClapTrap &operator=(const ClapTrap &clapTrap);  // CopyAssignmentConstructor
    ~ClapTrap();                                    // Destructor

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   private:
    std::string name_;
    unsigned int hitPoints_;
    unsigned int energyPoints_;
    unsigned int attackDamage_;
};

#endif