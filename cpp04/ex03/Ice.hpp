/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:36:04 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 17:54:13 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
   public:
    Ice(void);                       // Default Constructor
    Ice(const std::string &str);     // Constructor
    Ice(const Ice &ice);             // Copy Constructor
    Ice &operator=(const Ice &ice);  // Assignation Operator
    ~Ice();                          // Destructor

    std::string const &getType() const;
    virtual Ice *clone() const;
    virtual void use(ICharacter &target);

   private:
};

#endif