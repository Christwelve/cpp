/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:52:45 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 18:53:37 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat bureaucrat1("Bureaucrat1", 1);
    Bureaucrat bureaucrat2("Bureaucrat2", 150);

    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Robot");
    PresidentialPardonForm presidentialForm("Criminal");

    // Test ShrubberyCreationForm
    bureaucrat1.signForm(shrubberyForm);
    bureaucrat1.executeForm(shrubberyForm);

    // Test RobotomyRequestForm
    bureaucrat1.signForm(robotomyForm);
    bureaucrat1.executeForm(robotomyForm);

    // Test PresidentialPardonForm
    bureaucrat1.signForm(presidentialForm);
    bureaucrat1.executeForm(presidentialForm);

    // Test exceptions
    try {
        bureaucrat2.signForm(shrubberyForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bureaucrat2.executeForm(shrubberyForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}