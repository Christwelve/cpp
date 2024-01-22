/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:33 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/21 22:37:58 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#include "PmergeMe.hpp"

// Ford-Johnson Algorithm

template <typename T>
void PmergeMe<T>::sorting(T& container) {
    printContainer("Before", container);

    clock_t start = clock();
    getLeftover(container);
    n2Chunks(container);
    devideChains(container);
    applyJacobNumbers(container);
    clock_t end = clock();

    printContainer("After", container);
    if (this->duplicate_) {
        std::cout << YELLOW << "Info: " << CLEAR << this->duplicates_ << " duplicates detected and ignored" << std::endl;
    }
    std::cout << "Time to process a range of " << container.size() << " elements with " << GREEN << "std::" << ContainerType<T>::name() << CLEAR
              << ": " << GREEN << end - start << "us" << CLEAR << std::endl
              << std::endl;
}

template <typename T>
void PmergeMe<T>::getLeftover(T& container) {
    n_ = container.size();
    size_t end = n_;
    if (n_ % 2) {
        end = n_ - 1;
        leftover_ = true;
        leftoverNum_ = container[n_ - 1];
        container.erase(container.begin() + end);
    }
}

template <typename T>
void PmergeMe<T>::n2Chunks(T& container) {
    // n/2 larger num -> top
    for (size_t i = 0; i < container.size(); i += 2) {
        if (container[i] < container[i + 1]) std::swap(container[i], container[i + 1]);
    }

    // printContainer("Pair", container);
    sortPairsRecursively(container.begin(), container.end());
    // printContainer("Merge", container);
}

template <typename T>
void PmergeMe<T>::sortPairsRecursively(typename T::iterator begin, typename T::iterator end) {
    if (end - begin <= 2) {
        return;
    }

    typename T::iterator middle = begin + ((end - begin) / 2 & ~1);

    sortPairsRecursively(begin, middle);
    sortPairsRecursively(middle, end);

    mergePairs(begin, middle, end);
}

template <typename T>
void PmergeMe<T>::mergePairs(typename T::iterator begin, typename T::iterator middle, typename T::iterator end) {
    T temp(begin, end);

    typename T::iterator it_left = temp.begin(), it_right = temp.begin() + (middle - begin), it = begin;
    while (it_left != temp.begin() + (middle - begin) && it_right != temp.end()) {
        if (*it_left <= *it_right) {
            *it++ = *it_left++;
            *it++ = *it_left++;
        } else {
            *it++ = *it_right++;
            *it++ = *it_right++;
        }
    }

    while (it_left != temp.begin() + (middle - begin)) {
        *it++ = *it_left++;
        *it++ = *it_left++;
    }

    while (it_right != temp.end()) {
        *it++ = *it_right++;
        *it++ = *it_right++;
    }
}

template <typename T>
void PmergeMe<T>::devideChains(T& container) {
    for (int i = container.size() - 1; i >= 0; i -= 2) {
        buffer_.push_back(container[i]);
        container.erase(container.begin() + i);
    }
    std::reverse(buffer_.begin(), buffer_.end());

    // printContainer("Main", container);
    // std::cout << "Buffer : ";
    // for (size_t i = 0; i < buffer_.size(); i++) {
    //     std::cout << buffer_[i] << " ";
    // }
    // std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::applyJacobNumbers(T& container) {
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
        typename T::iterator it = std::lower_bound(container.begin(), container.end(), buffer_[index]);
        container.insert(it, buffer_[index]);

        for (size_t i = nextIndex; i < index; ++i) {
            it = std::lower_bound(container.begin(), container.end(), buffer_[i]);
            container.insert(it, buffer_[i]);
        }

        nextIndex = index + 1;
    }

    for (size_t i = nextIndex; i < buffer_.size(); ++i) {
        typename T::iterator it = std::lower_bound(container.begin(), container.end(), buffer_[i]);
        container.insert(it, buffer_[i]);
    }

    if (leftover_) {
        typename T::iterator it = std::lower_bound(container.begin(), container.end(), leftoverNum_);
        container.insert(it, leftoverNum_);
    }
}
