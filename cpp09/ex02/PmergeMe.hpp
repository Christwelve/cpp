/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:16:19 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/18 20:23:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <queue>
#include <vector>

class PmergeMe {
   public:
    PmergeMe(void);                                 // Default Constructor
    PmergeMe(const unsigned int[]);                 // Constructor
    PmergeMe(const PmergeMe &pmergeMe);             // Copy Constructor
    PmergeMe &operator=(const PmergeMe &pmergeMe);  // Assignation Operator
    ~PmergeMe();                                    // Destructor

   private:
    std::vector<unsigned int> vStack_;
    std::queue<unsigned int> qStack_;
};

#endif