/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:16:19 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/20 12:00:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define CLEAR "\033[0m"

#define MAX_AMOUNT_NBRS 5000

class PmergeMe {
   public:
    PmergeMe(void);                                 // Default Constructor
    PmergeMe(int argc, char **argv);                // Constructor
    PmergeMe(const PmergeMe &pmergeMe);             // Copy Constructor
    PmergeMe &operator=(const PmergeMe &pmergeMe);  // Assignation Operator
    ~PmergeMe();                                    // Destructor

   private:
    std::vector<size_t> vStack_;
    std::deque<size_t> qStack_;
    size_t n_;
    bool leftover_;
    size_t leftoverNum_;
    int parsing(int argc, char **argv);

    void sorting(void);
    void n2Chunks(void);
    void sortPairsRecursively(void);

    void devideChains(void);
    // void applyJNs(void);
    // size_t binarySearch(void);
    // void leftover(void);
};

#endif