/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:58 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/20 15:30:46 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argv == NULL || argc == 1) {
        std::cout << RED << "Error: " << CLEAR << "Please use: ./PmergeMe [uint1] [uint2] ..." << std::endl;
        return (1);
    }
    std::vector<size_t> vec;
    PmergeMe<std::vector<size_t> > first(argc, argv, vec);

    std::deque<size_t> deque;
    PmergeMe<std::deque<size_t> > second(argc, argv, deque);

    std::cout << "End" << std::endl;
}