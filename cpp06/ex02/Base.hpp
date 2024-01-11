/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:56:29 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 06:59:02 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
   public:
    Base(void);                         // Default Constructor
    Base(const Base& base);             // Copy Constructor
    Base& operator=(const Base& base);  // Assignment Operator
    virtual ~Base();                    // Destructor

   private:
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify_from_pointer(Base* p);
void identify_from_reference(Base& ref);

#endif