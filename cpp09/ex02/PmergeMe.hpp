/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:16:19 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/22 09:09:29 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <string>
#include <vector>

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define CLEAR "\033[0m"

#define MAX_AMOUNT_NBRS 30000

template <typename T>
class PmergeMe {
   public:
    PmergeMe();                                     // Default Constructor
    PmergeMe(int argc, char** argv, T& container);  // Constructor
    PmergeMe(const PmergeMe& pmergeMe);             // Copy Constructor
    PmergeMe& operator=(const PmergeMe& pmergeMe);  // Assignation Operator
    ~PmergeMe();                                    // Destructor

   private:
    size_t n_;
    bool leftover_;
    size_t leftoverNum_;
    std::vector<size_t> buffer_;
    bool duplicate_;
    size_t duplicates_;

    int parseArguments(int argc, char** argv, T& container);
    void printContainer(const std::string& str, T& container);

    void sorting(T& container);
    void getLeftover(T& container);
    void n2Chunks(T& container);
    void sortPairsRecursively(typename T::iterator begin, typename T::iterator end);
    void mergePairs(typename T::iterator begin, typename T::iterator middle, typename T::iterator end);
    void devideChains(T& container);
    void applyJacobNumbers(T& container);
};

extern template class PmergeMe<std::vector<size_t> >;
extern template class PmergeMe<std::deque<size_t> >;

template <typename T>
struct ContainerType {
    static std::string name() { return "unknown"; }
};

template <>
struct ContainerType<std::vector<size_t> > {
    static std::string name() { return "vector"; }
};

template <>
struct ContainerType<std::deque<size_t> > {
    static std::string name() { return "deque"; }
};

#include "Sorting.tpp"

#endif