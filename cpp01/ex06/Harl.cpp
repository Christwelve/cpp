/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:17:55 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 16:13:04 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int i;
    for (i = 0; i < 4; i++) {
        if (levels[i] == level) {
            break;
        }
    }

    switch (i) {
        case 0:
            (this->*funcs[0])();
        case 1:
            (this->*funcs[1])();
        case 2:
            (this->*funcs[2])();
        case 3:
            (this->*funcs[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
    }
}

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
              << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put "
                 "enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
              << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming "
                 "for years whereas you started working here since last month.\n"
              << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}
