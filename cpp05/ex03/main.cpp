/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:52:45 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/03 15:53:24 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Intern.hpp"

int main(void) {
        const std::string formNames[] = {"robotomy request", "presidential pardon",
                                     "shrubbery creation", "blaaa"};

    Intern intern;
    for (int i = 0; i < 4; i++) {
        std::cout << "-------------------------" << std::endl;
        std::cout << "Test " << i << std::endl;
        std::cout << "-------------------------" << std::endl;
        AForm *form = intern.makeForm(formNames[i], "target");
        if (form != NULL) {
            std::cout << *form << std::endl;
            delete form;
        }
    }

    return 0;
}