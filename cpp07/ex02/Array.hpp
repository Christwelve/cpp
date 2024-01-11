/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:00:47 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 15:01:07 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
   public:
    Array(void);                            // Default Constructor
    Array(const unsigned int &n);           // Constructor
    Array(const Array &source);             // Copy Constructor
    Array &operator=(const Array &source);  // Assignation Operator
    ~Array();                               // Destructor

    unsigned int size(void) const;

   private:
    T *array_;
    unsigned int size_;
};

#include "Array.tpp"
#endif