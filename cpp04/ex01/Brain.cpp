/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:48:14 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/13 12:48:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain(void) { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &brain) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas_[i] = brain.ideas_[i];
    }
    return (*this);
}

Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }
