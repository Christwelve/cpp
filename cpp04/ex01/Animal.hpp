/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:26:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/14 08:54:06 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
   public:
    Animal(void);                             // Default constructor
    Animal(const std::string &str);           // Constructor
    Animal(const Animal &animal);             // Copy constructor
    Animal &operator=(const Animal &animal);  // Copy assignment operator overload
    virtual ~Animal();                        // Destructor

    virtual void makeSound(void) const;
    std::string getType(void) const;

   protected:
    std::string type_;
};

#endif