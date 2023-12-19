/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:34:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/19 21:47:43 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap();                                     // Default Constructor
    FragTrap(std::string name);                     // Constructor
    FragTrap(const FragTrap &fragTrap);             // CopyConstructor
    FragTrap &operator=(const FragTrap &fragTrap);  // CopyAssignmentConstructor
    ~FragTrap();                                    // Destructor

    void highFivesGuys();

   private:
};

#endif