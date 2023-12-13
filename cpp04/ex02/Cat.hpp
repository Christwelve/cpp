/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:03:49 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 12:52:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat(void);                       // Default Constructor
    Cat(const Cat &cat);             // Copy Constructor
    Cat &operator=(const Cat &cat);  // Assignation Operator
    ~Cat();                          // Destructor

    void makeSound(void) const;

   private:
    Brain *brain_;
};

#endif