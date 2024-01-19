/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:16:19 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/19 22:51:04 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define CLEAR "\033[0m"

class PmergeMe {
   public:
    PmergeMe(void);                                 // Default Constructor
    PmergeMe(int argc, char **argv);                // Constructor
    PmergeMe(const PmergeMe &pmergeMe);             // Copy Constructor
    PmergeMe &operator=(const PmergeMe &pmergeMe);  // Assignation Operator
    ~PmergeMe();                                    // Destructor

   private:
    std::vector<unsigned int> vStack_;
    std::deque<unsigned int> qStack_;
    size_t n_;
    int parsing(int argc, char **argv);

    void sorting(void);
    void n2Chunks(void);
    void sortPairsRecursively(size_t end);

    void devideChains(void);
    void applyJNs(void);
    size_t binarySearch(void);
    void leftover(void);
};

#endif