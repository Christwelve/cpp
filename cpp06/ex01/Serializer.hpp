/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:07:03 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/13 16:19:44 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

struct Data {
    int n;
    std::string s1;
};

class Serializer {
   public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

   private:
    Serializer(void);                                     // Default Constructor
    Serializer(const Serializer &serializer);             // Copy Constructor
    Serializer &operator=(const Serializer &serializer);  // Assignation Operator
    ~Serializer();
};

#endif
