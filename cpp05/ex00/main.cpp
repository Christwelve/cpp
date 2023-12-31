/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:52:45 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/30 14:59:23 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat bureaucrat("Alice", 150);
    Bureaucrat bureaucrat2("Bob", 1);

    try {
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.incrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}