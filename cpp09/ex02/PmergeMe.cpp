/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:44 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/19 22:54:14 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>

PmergeMe::PmergeMe(void) { return; }

PmergeMe::PmergeMe(int argc, char **argv) {
    if (parsing(argc, argv)) return;
    sorting();
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    this->vStack_ = other.vStack_;
    this->qStack_ = other.qStack_;
    return *this;
}

PmergeMe::~PmergeMe(void) { return; }

int PmergeMe::parsing(int argc, char **argv) {
    double check;
    char trash;
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        if (!(ss >> check) || check < 0 || check > UINT_MAX || ss >> trash) {
            std::cout << RED << "Error: " << CLEAR << "Invalid number at position: " << i << std::endl;
            return (1);
        }

        unsigned int num = static_cast<unsigned int>(check);
        if (std::find(this->vStack_.begin(), this->vStack_.end(), num) == this->vStack_.end()) {
            this->vStack_.push_back(num);
            this->qStack_.push_back(num);
        } else {
            std::cout << YELLOW << "Info: " << CLEAR << "Duplicate in position " << i << " detected and ignored" << std::endl;
        }
    }

    // // Print vStack_
    std::cout << "After parsing" << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }

    // // Print qStack_
    // for (size_t i = 0; i < this->qStack_.size(); i++) {
    //     std::cout << "qStack[" << i << "] = " << this->qStack_[i] << std::endl;
    // }

    return (0);
}

// Ford-Johnson Algorithm

void PmergeMe::sortPairsRecursively(size_t end) {
    if (end <= 2) {
        return;
    }

    for (size_t i = 0; i < end - 2; i += 2) {
        if (vStack_[i] > vStack_[i + 2]) {
            std::swap(vStack_[i], vStack_[i + 2]);
            std::swap(vStack_[i + 1], vStack_[i + 3]);
        }
    }

    // Recursive call
    sortPairsRecursively(end - 2);
}

void PmergeMe::n2Chunks(void) {
    n_ = this->vStack_.size();
    std::cout << "n_: " << n_ << std::endl;
    size_t end = n_;
    if (n_ % 2) end = n_ - 1;
    std::cout << "end: " << end << std::endl;

    // n/2 larger num -> top
    for (size_t i = 0; i < end; i += 2) {
        if (vStack_[i] < vStack_[i + 1]) std::swap(vStack_[i], vStack_[i + 1]);
    }
    std::cout << "\nAfter single pair sort" << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }
    sortPairsRecursively(end);
    std::cout << "\nAfter pair sort " << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }
}

void PmergeMe::sorting(void) {
    n2Chunks();
    // devideChains();
    // applyJNs();
    // leftover();
}
// 1) Dividing and sorting in n/2 chunks
// 2) Creating main and buffer chain
// 3) Creating Jacobsnumbers while (i < jz.size()) {for(jz > jz-1: jz--) {insert buffer[i]} => binary search!
// 4) Insert struggler
