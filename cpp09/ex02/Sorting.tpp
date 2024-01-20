/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:33 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/20 17:41:55 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <ctime>
#include <typeinfo>
#include <string>

#include "PmergeMe.hpp"

// Ford-Johnson Algorithm

std::string printContainerType(const std::string& typeName) {
    if (typeName.find("deque") != std::string::npos) {
        return "deque";
    } else if (typeName.find("vector") != std::string::npos) {
        return "vector";
    } else {
        return "Unknown container type";
    }
}


template <typename T>
void PmergeMe<T>::sorting(T& container) {
    clock_t start = clock();

    getLeftover(container);
    n2Chunks(container);
    devideChains(container);
    applyJacobNumbers(container);

    clock_t end = clock();
    double diff = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // std::cout << "Time to process a range of " << container.size() << " elements with " << printContainerType(typeid(container).name()) << " : " << diff << " s\n";
    std::cout << "Time to process a range of " << container.size() << " elements with " << " : " << diff << " s\n";
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
    // std::cout << "\nAfter single pair sort" << std::endl;
    // for (size_t i = 0; i < container.size(); i++) {
    //     std::cout << "container[" << i << "] = " << container[i] << std::endl;
    // }
    sortPairsRecursively(container);
    // std::cout << "\nAfter pair sort " << std::endl;
    // for (size_t i = 0; i < container.size(); i++) {
    //     std::cout << "container[" << i << "] = " << container[i] << std::endl;
    // }
}

template <typename T>
void PmergeMe<T>::sortPairsRecursively(T& container) {
    if (container.size() <= 2) {
        return;
    }

    bool swapped = false;
    for (size_t i = 0; i < container.size() - 3; i += 2) {
        if (container[i] > container[i + 2]) {
            std::swap(container[i], container[i + 2]);
            std::swap(container[i + 1], container[i + 3]);
            swapped = true;
        }
    }
    if (swapped) sortPairsRecursively(container);
}

template <typename T>
void PmergeMe<T>::devideChains(T& container) {
    for (int i = container.size() - 1; i >= 0; i -= 2) {
        buffer_.push_back(container[i]);
        container.erase(container.begin() + i);
    }
    std::reverse(buffer_.begin(), buffer_.end());

    // Printing States of vStack and buffer_
    // std::cout << "\nvStack after dividing " << std::endl;
    // for (size_t i = 0; i < container.size(); i++) {
    //     std::cout << "container[" << i << "] = " << container[i] << std::endl;
    // }
    // std::cout << "\nbuffer_ after dividing " << std::endl;
    // for (size_t i = 0; i < buffer_.size(); i++) {
    //     std::cout << "buffer__[" << i << "] = " << buffer_[i] << std::endl;
    // }
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

    std::cout << "After:    ";
    for (size_t i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}
