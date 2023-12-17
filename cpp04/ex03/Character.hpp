/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:48:24 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 17:46:57 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter {
   public:
    Character(void);                                   // Default Constructor
    Character(const std::string &str);                 // Constructor
    Character(const Character &character);             // Copy Constructor
    Character &operator=(const Character &character);  // Assignation Operator
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

   private:
    std::string name_;
    AMateria *materia_[4];
};

#endif