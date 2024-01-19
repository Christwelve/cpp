/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:58 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/19 14:26:18 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    (void)argv;
    (void)argc;
    if (argv == NULL || argc == 1) {
        std::cout << RED << "Error: " << CLEAR << "Please use: ./PmergeMe [uint1] [uint2] ..." << std::endl;
        return (1);
    }

    PmergeMe test(argc, argv);

    std::cout << "End" << std::endl;
}