/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:17 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 21:57:23 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &intern) { *this = intern; }

Intern &Intern::operator=(const Intern &intern) {
    if (this != &intern) {
    }
    return (*this);
}
Intern::~Intern(void) {}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    const std::string names[3] = {"robotomy request", "presidential pardon",
                                  "shrubbery creation"};

    for (int i = 0; i < 3; i++) {
        if (name == names[i]) {
            std::cout << name << std::endl;
            std::cout << "Intern creates " << name << std::endl;
            switch (i) {
                case 0:
                    return (new RobotomyRequestForm(target));
                case 1:
                    return (new PresidentialPardonForm(target));
                case 2:
                    return (new ShrubberyCreationForm(target));
                default:
                    break;
            }
        }
    }
    std::cerr << "Intern cannot create " << name << std::endl;
    return (NULL);
}