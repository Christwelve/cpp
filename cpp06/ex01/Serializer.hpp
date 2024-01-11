/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:07:03 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 07:11:21 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data {
    int n;
    std::string s1;
};

class Serializer {
   public:
    static unsigned long serialize(Data *ptr);
    static Data *deserialize(unsigned long raw);

   private:
    Serializer(void);                                     // Default Constructor
    Serializer(const Serializer &serializer);             // Copy Constructor
    Serializer &operator=(const Serializer &serializer);  // Assignation Operator
    ~Serializer();
};

#endif
