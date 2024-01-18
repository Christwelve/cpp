/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:28:36 by christianme       #+#    #+#             */
/*   Updated: 2024/01/18 16:39:37 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cout << RED << "Error: " << CLEAR << "Usage: ./RPN <string>" << std::endl;
        return (1);
    }
    
    RPN rpn;
    rpn.calculate(argv[1]);


    return 0;
}