/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:44 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/20 12:03:12 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
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

void PmergeMe::sortPairsRecursively() {
    if (vStack_.size() <= 2) {
        return;
    }

    bool swapped = false;
    for (size_t i = 0; i < vStack_.size() - 3; i += 2) {
        if (vStack_[i] > vStack_[i + 2]) {
            std::swap(vStack_[i], vStack_[i + 2]);
            std::swap(vStack_[i + 1], vStack_[i + 3]);
            swapped = true;
        }
    }
    if (swapped) sortPairsRecursively();
}

void PmergeMe::n2Chunks(void) {
    // n/2 larger num -> top
    for (size_t i = 0; i < vStack_.size(); i += 2) {
        if (vStack_[i] < vStack_[i + 1]) std::swap(vStack_[i], vStack_[i + 1]);
    }
    std::cout << "\nAfter single pair sort" << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }
    sortPairsRecursively();
    std::cout << "\nAfter pair sort " << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }
    devideChains();
}

void PmergeMe::devideChains() {
    std::vector<size_t> buffer;
    for (int i = vStack_.size() - 1; i >= 0; i -= 2) {
        buffer.push_back(vStack_[i]);
        vStack_.erase(vStack_.begin() + i);
    }
    std::reverse(buffer.begin(), buffer.end());

    // Printing States of vStack and buffer
    std::cout << "\nvStack after dividing " << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }
    std::cout << "\nBuffer after dividing " << std::endl;
    for (size_t i = 0; i < buffer.size(); i++) {
        std::cout << "buffer_[" << i << "] = " << buffer[i] << std::endl;
    }

    // Generating Jacob Numbers
    std::vector<size_t> jacobsIndices;
    size_t jacob = 0;
    for (size_t i = 2; jacob < MAX_AMOUNT_NBRS; ++i) {
        jacob = static_cast<size_t>(std::floor((std::pow(2, i) - std::pow(-1, i)) / 3));
        jacobsIndices.push_back(jacob - 1);
    }
    // std::cout << "\njacobsIndices " << std::endl;
    // for (size_t i = 0; i < 15; i++) {
    //     std::cout << "jacobsIndices[" << i << "] = " << jacobsIndices[i] << std::endl;
    // }

    // Apply Jacob Numbers
    size_t nextIndex = 0;
    for (size_t j = 0; j < jacobsIndices.size(); ++j) {
        size_t index = jacobsIndices[j];
        if (index >= buffer.size()) {
            break;
        }
        std::vector<size_t>::iterator it = std::lower_bound(vStack_.begin(), vStack_.end(), buffer[index]);
        vStack_.insert(it, buffer[index]);

        for (size_t i = nextIndex; i < index; ++i) {
            it = std::lower_bound(vStack_.begin(), vStack_.end(), buffer[i]);
            vStack_.insert(it, buffer[i]);
        }

        nextIndex = index + 1;
    }

    for (size_t i = nextIndex; i < buffer.size(); ++i) {
        std::vector<size_t>::iterator it = std::lower_bound(vStack_.begin(), vStack_.end(), buffer[i]);
        vStack_.insert(it, buffer[i]);
    }

    if (leftover_) {
        std::vector<size_t>::iterator it = std::lower_bound(vStack_.begin(), vStack_.end(), leftoverNum_);
        vStack_.insert(it, leftoverNum_);
    }

    std::cout << "\nvStack after applying Jacob Numbers " << std::endl;
    for (size_t i = 0; i < this->vStack_.size(); i++) {
        std::cout << "vStack_[" << i << "] = " << this->vStack_[i] << std::endl;
    }
}

void PmergeMe::sorting(void) {
    n_ = this->vStack_.size();
    std::cout << "n_: " << n_ << std::endl;
    size_t end = n_;
    if (n_ % 2) {
        end = n_ - 1;
        leftover_ = true;
        leftoverNum_ = vStack_[n_ - 1];
        vStack_.erase(vStack_.begin() + end);
    }

    n2Chunks();
    // devideChains();
    // applyJNs();
    // leftover();
}
// 1) Dividing and sorting in n/2 chunks
// 2) Creating main and buffer chain
// 3) Creating Jacobsnumbers while (i < jz.size()) {for(jz > jz-1: jz--) {insert buffer[i]} => binary search!
// 4) Insert struggler
