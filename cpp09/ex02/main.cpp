/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:58 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/21 21:01:45 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argv == NULL || argc == 1) {
        std::cout << RED << "Error: " << CLEAR << "Please use: ./PmergeMe [uint1] [uint2] ..." << std::endl;
        return (1);
    }

    if (argc > MAX_AMOUNT_NBRS + 1) {
        std::cout << RED << "Error: " << CLEAR
                  << "If you want to sort more numbers, please modify the MAX_AMOUNT_NBR in .hpp + check in applyJacobsNumers() if "
                     "'size_t jacob' can still handle the highest jacob number. \n"
                  << GREEN << "You're welcome!" << CLEAR << std::endl;
        return (1);
    }

    std::vector<size_t> vec;
    std::deque<size_t> deque;

    PmergeMe<std::vector<size_t> > first(argc, argv, vec);
    PmergeMe<std::deque<size_t> > second(argc, argv, deque);


    return (0);
}
