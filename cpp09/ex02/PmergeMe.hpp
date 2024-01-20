/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:16:19 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/20 17:42:03 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define CLEAR "\033[0m"

#define MAX_AMOUNT_NBRS 3000

// std::string printContainerType(const std::string& typeName);

template <typename T>
class PmergeMe {
   public:
    PmergeMe(void);                                 // Default Constructor
    PmergeMe(int argc, char** argv, T& container);  // Constructor
    PmergeMe(const PmergeMe& pmergeMe);             // Copy Constructor
    PmergeMe& operator=(const PmergeMe& pmergeMe);  // Assignation Operator
    ~PmergeMe();                                    // Destructor

   private:
    size_t n_;
    bool leftover_;
    size_t leftoverNum_;
    std::vector<size_t> buffer_;
    size_t duplicates_;

    int parseArguments(int argc, char** argv, T& container);

    void sorting(T& container);
    void getLeftover(T& container);
    void n2Chunks(T& container);
    void sortPairsRecursively(T& container);
    void devideChains(T& container);
    void applyJacobNumbers(T& container);
};

extern template class PmergeMe<std::vector<size_t> >;
extern template class PmergeMe<std::deque<size_t> >;

#include "Sorting.tpp"

#endif