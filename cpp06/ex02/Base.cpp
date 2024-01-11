/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:56:58 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 07:04:59 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <iostream>

Base::Base(void) { return; }

Base::Base(const Base &base) {
    *this = base;
    return;
}

Base &Base::operator=(const Base &base) {
    (void)base;
    return (*this);
}

Base::~Base(void) { return; }

Base *generate(void) {
    int i = rand() % 3;
    if (i == 0) {
        std::cout << "Generated:        A" << std::endl;
        return (new A);
    } else if (i == 1) {
        std::cout << "Generated:        B" << std::endl;
        return (new B);
    } else {
        std::cout << "Generated:        C" << std::endl;
        return (new C);
    }
}

void identify_from_pointer(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "Pointer ident:    A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "Pointer ident:    B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "Pointer ident:    C" << std::endl;
    }
}

void identify_from_reference(Base &ref) {
    try {
        (void)dynamic_cast<A &>(ref);
        std::cout << "Ref ident:        A" << std::endl;
    } catch (std::exception &e) {
        try {
            (void)dynamic_cast<B &>(ref);
            std::cout << "Ref ident:        B" << std::endl;
        } catch (std::exception &e) {
            (void)dynamic_cast<C &>(ref);
            std::cout << "Ref ident:        C" << std::endl;
        }
    }
}