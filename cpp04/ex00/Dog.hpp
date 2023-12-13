/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:52:53 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 10:09:17 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
   public:
    Dog(void);                       // Default constructor
    Dog(const Dog &dog);             // Copy constructor
    Dog &operator=(const Dog &dog);  // Assignation operator overload
    ~Dog();                          // Destructor

    void makeSound(void) const;

   private:
};

#endif