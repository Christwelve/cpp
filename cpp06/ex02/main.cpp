/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:51:10 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 07:04:09 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ". Test:" << std::endl;
        Base *base = generate();
        identify_from_pointer(base);
        identify_from_reference(*base);
        delete base;
        std::cout << std::endl;
    }
    return (0);
}