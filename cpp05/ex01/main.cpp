/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:52:45 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/31 14:41:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bureaucrat1("Alice", 1);
    Bureaucrat bureaucrat2("Bob", 150);
    Form form1("Form1", 1, 1);
    Form form2("Form2", 150, 150);

    std::cout << bureaucrat1 << std::endl;
    std::cout << bureaucrat2 << std::endl;
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;

    try {
        bureaucrat1.signForm(form1);
        bureaucrat2.signForm(form2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;

    try {
        bureaucrat2.signForm(form1);
        bureaucrat1.signForm(form2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;

    return 0;
}