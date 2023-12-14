/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:22:27 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 09:23:25 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria {
   public:
    AMateria(void);                                 // Default Constructor
    AMateria(const std::string &type);              // Constructor
    AMateria(const AMateria &aMateria);             // Copy Constructor
    AMateria &operator=(const AMateria &aMateria);  // Copy assignment Operator
    ~AMateria();                                    // Destructor

    std::string const &getType() const;  // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

   protected:
    std::string type_;
};

#endif