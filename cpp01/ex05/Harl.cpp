/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 13:44:17 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            return;
        }
    }

    std::cout << "Invalid level: " << level << std::endl;
    std::cout << "Use DEBUG, INFO, WARNING or ERROR " << std::endl;
}

void Harl::debug() {
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put "
                 "enough bacon in my burger! If you did, I wouldn't be asking for more!"
              << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming "
                 "for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
