/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:00:19 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 19:29:44 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    ScavTrap();                          // Default Constructor
    ScavTrap(std::string name);          // Constructor
    ScavTrap(const ScavTrap &skavTrap);  // CopyConstructor
    ~ScavTrap();                         // Destructor

    ScavTrap &operator=(const ScavTrap &skavTrap);

    void attack(const std::string &target);
    void guardGate();

   private:
};

#endif