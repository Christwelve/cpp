/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:52:45 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/03 16:05:19 by cmeng            ###   ########.fr       */
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
    std::cout << "--------shrubbery--------" << std::endl;
    bureaucrat1.signForm(shrubberyForm);
    bureaucrat1.executeForm(shrubberyForm);
    std::cout << "-------------------------" << std::endl;

    // Test RobotomyRequestForm
    std::cout << "--------robo--------" << std::endl;
    bureaucrat1.signForm(robotomyForm);
    bureaucrat1.executeForm(robotomyForm);
    std::cout << "--------------------" << std::endl;

    // Test PresidentialPardonForm
    std::cout << "--------presi--------" << std::endl;
    bureaucrat1.signForm(presidentialForm);
    bureaucrat1.executeForm(presidentialForm);
    std::cout << "---------------------" << std::endl;

    // Test exceptions
    std::cout << "--------exceptions--------" << std::endl;
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
    std::cout << "---------------------------" << std::endl;

    return 0;
}