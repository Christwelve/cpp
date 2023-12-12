/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:34:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 19:53:29 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap();                          // Default Constructor
    FragTrap(std::string name);          // Constructor
    FragTrap(const FragTrap &fragTrap);  // CopyConstructor
    ~FragTrap();                         // Destructor

    FragTrap &operator=(const FragTrap &fragTrap);

    void highFivesGuys();

   private:
};

#endif