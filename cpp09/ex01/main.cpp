/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:28:36 by christianme       #+#    #+#             */
/*   Updated: 2024/01/18 17:48:30 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << RED << "Error: " << CLEAR << "Usage: ./RPN <string>" << std::endl;
        return (1);
    }

    RPN rpn;
    rpn.calculate(argv[1]);

    return (0);
}