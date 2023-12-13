/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:18:47 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 12:35:01 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
   public:
    WrongAnimal(void);                                  // Default constructor
    WrongAnimal(const std::string &str);                // Constructor
    WrongAnimal(const WrongAnimal &animal);             // Copy constructor
    WrongAnimal &operator=(const WrongAnimal &animal);  // Assignation operator overload
    virtual ~WrongAnimal();                             // Destructor

    void makeSound(void) const;
    std::string getType(void) const;

   protected:
    std::string type_;
};

#endif