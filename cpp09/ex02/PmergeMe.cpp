/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:44 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/21 22:49:39 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <sstream>

template <typename T>
PmergeMe<T>::PmergeMe(void) {
    return;
}

template <typename T>
PmergeMe<T>::PmergeMe(int argc, char **argv, T &container) : leftover_(false), duplicate_(false), duplicates_(0) {
    if (parseArguments(argc, argv, container)) return;
    sorting(container);
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) {
    if (this != &other) {
        *this = other;
    }
    return;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &other) {
    if (this != &other) {
        n_ = other.n_;
        leftover_ = other.leftover_;
        leftoverNum_ = other.leftoverNum_;
        buffer_ = other.buffer_;
        duplicate_ = other.duplicate_;
        duplicates_ = other.duplicates_;
    }
    return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe(void) {
    return;
}

template <typename T>
int PmergeMe<T>::parseArguments(int argc, char **argv, T &container) {
    double check;
    char trash;
    duplicates_ = 0;
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        if (!(ss >> check) || check < 0 || check > UINT_MAX || ss >> trash) {
            std::cout << RED << "Error: " << CLEAR << "Invalid number at position: " << i << std::endl;
            return (1);
        }

        unsigned int num = static_cast<unsigned int>(check);
        if (std::find(container.begin(), container.end(), num) == container.end()) {
            container.push_back(num);
        } else {
            this->duplicate_ = true;
            this->duplicates_++;
        }
    }
    return (0);
}

template <typename T>
void PmergeMe<T>::printContainer(const std::string &str, T &container) {
    std::cout << str << " : ";
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template class PmergeMe<std::vector<size_t> >;
template class PmergeMe<std::deque<size_t> >;