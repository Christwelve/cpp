/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:24:45 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 17:53:16 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
   public:
    Cure(void);                         // Default Constructor
    Cure(const std::string &str);       // Constructor
    Cure(const Cure &cure);             // Copy Constructor
    Cure &operator=(const Cure &cure);  // Assignation Operator
    ~Cure();                            // Destructor

    std::string const &getType() const;
    virtual Cure *clone() const;
    virtual void use(ICharacter &target);

   private:
};

#endif