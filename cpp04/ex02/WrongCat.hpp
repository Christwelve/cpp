/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:19:28 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 12:21:11 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat(void);                            // Default Constructor
    WrongCat(const WrongCat &cat);             // Copy Constructor
    WrongCat &operator=(const WrongCat &cat);  // Assignation Operator
    ~WrongCat();                               // Destructor

    void makeSound(void) const;

   private:
};

#endif