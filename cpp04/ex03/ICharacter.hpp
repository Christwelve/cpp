/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:35:48 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 08:54:06 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter {
   public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;

    // ICharacter(void); // Default Constructor ICharacter(const std::string &str);
    // // Constructor ICharacter(const ICharacter &iCharacter);				//
    // Copy Constructor ICharacter &operator=(const ICharacter &iCharacter);    //
    // Copy assignment Operator ~ICharacter();
    // // Destructor

   private:
};

#endif