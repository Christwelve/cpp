/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:19:44 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/20 13:15:26 by cmeng            ###   ########.fr       */
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
    if (parseArguments(argc, argv)) return;
    sorting();
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    this->vec_ = other.vec_;
    this->deque_ = other.deque_;
    return *this;
}

PmergeMe::~PmergeMe(void) { return; }

int PmergeMe::parseArguments(int argc, char **argv) {
    double check;
    char trash;
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        if (!(ss >> check) || check < 0 || check > UINT_MAX || ss >> trash) {
            std::cout << RED << "Error: " << CLEAR << "Invalid number at position: " << i << std::endl;
            return (1);
        }

        unsigned int num = static_cast<unsigned int>(check);
        if (std::find(this->vec_.begin(), this->vec_.end(), num) == this->vec_.end()) {
            this->vec_.push_back(num);
            this->deque_.push_back(num);
        } else {
            std::cout << YELLOW << "Info: " << CLEAR << "Duplicate in position " << i << " detected and ignored" << std::endl;
        }
    }

    // // Print vec_
    // std::cout << "After parsing" << std::endl;
    // for (size_t i = 0; i < this->vec_.size(); i++) {
    //     std::cout << "vec_[" << i << "] = " << this->vec_[i] << std::endl;
    // }

    // // Print deque_
    // for (size_t i = 0; i < this->deque_.size(); i++) {
    //     std::cout << "qStack[" << i << "] = " << this->deque_[i] << std::endl;
    // }

    return (0);
}

// Ford-Johnson Algorithm

void PmergeMe::sortPairsRecursively() {
    if (vec_.size() <= 2) {
        return;
    }

    bool swapped = false;
    for (size_t i = 0; i < vec_.size() - 3; i += 2) {
        if (vec_[i] > vec_[i + 2]) {
            std::swap(vec_[i], vec_[i + 2]);
            std::swap(vec_[i + 1], vec_[i + 3]);
            swapped = true;
        }
    }
    if (swapped) sortPairsRecursively();
}

void PmergeMe::n2Chunks(void) {
    // n/2 larger num -> top
    for (size_t i = 0; i < vec_.size(); i += 2) {
        if (vec_[i] < vec_[i + 1]) std::swap(vec_[i], vec_[i + 1]);
    }
    // std::cout << "\nAfter single pair sort" << std::endl;
    // for (size_t i = 0; i < this->vec_.size(); i++) {
    //     std::cout << "vec_[" << i << "] = " << this->vec_[i] << std::endl;
    // }
    sortPairsRecursively();
    // std::cout << "\nAfter pair sort " << std::endl;
    // for (size_t i = 0; i < this->vec_.size(); i++) {
    //     std::cout << "vec_[" << i << "] = " << this->vec_[i] << std::endl;
    // }
}

void PmergeMe::devideChains() {
    for (int i = vec_.size() - 1; i >= 0; i -= 2) {
        buffer_.push_back(vec_[i]);
        vec_.erase(vec_.begin() + i);
    }
    std::reverse(buffer_.begin(), buffer_.end());

    // Printing States of vStack and buffer_
    // std::cout << "\nvStack after dividing " << std::endl;
    // for (size_t i = 0; i < this->vec_.size(); i++) {
    //     std::cout << "vec_[" << i << "] = " << this->vec_[i] << std::endl;
    // }
    // std::cout << "\nbuffer_ after dividing " << std::endl;
    // for (size_t i = 0; i < buffer_.size(); i++) {
    //     std::cout << "buffer__[" << i << "] = " << buffer_[i] << std::endl;
    // }
}

void PmergeMe::applyJacobNumbers() {
    // Generating Jacob Numbers
    std::vector<size_t> jacobsIndices;
    size_t jacob = 0;
    for (size_t i = 2; jacob < MAX_AMOUNT_NBRS; ++i) {
        jacob = static_cast<size_t>(std::floor((std::pow(2, i) - std::pow(-1, i)) / 3));
        jacobsIndices.push_back(jacob - 1);
    }

    // Apply Jacob Numbers
    size_t nextIndex = 0;
    for (size_t j = 0; j < jacobsIndices.size(); ++j) {
        size_t index = jacobsIndices[j];
        if (index >= buffer_.size()) {
            break;
        }
        std::vector<size_t>::iterator it = std::lower_bound(vec_.begin(), vec_.end(), buffer_[index]);
        vec_.insert(it, buffer_[index]);

        for (size_t i = nextIndex; i < index; ++i) {
            it = std::lower_bound(vec_.begin(), vec_.end(), buffer_[i]);
            vec_.insert(it, buffer_[i]);
        }

        nextIndex = index + 1;
    }

    for (size_t i = nextIndex; i < buffer_.size(); ++i) {
        std::vector<size_t>::iterator it = std::lower_bound(vec_.begin(), vec_.end(), buffer_[i]);
        vec_.insert(it, buffer_[i]);
    }

    if (leftover_) {
        std::vector<size_t>::iterator it = std::lower_bound(vec_.begin(), vec_.end(), leftoverNum_);
        vec_.insert(it, leftoverNum_);
    }

    // std::cout << "vStack after applying Jacob Numbers " << std::endl;
    // for (size_t i = 0; i < this->vec_.size(); i++) {
    //     std::cout << "vec_[" << i << "] = " << this->vec_[i] << std::endl;
    // }
}

void PmergeMe::getLeftover(void) {
    n_ = this->vec_.size();
    size_t end = n_;
    if (n_ % 2) {
        end = n_ - 1;
        leftover_ = true;
        leftoverNum_ = vec_[n_ - 1];
        vec_.erase(vec_.begin() + end);
    }
}

void PmergeMe::sorting(void) {
    getLeftover();
    n2Chunks();
    devideChains();
    applyJacobNumbers();
}
