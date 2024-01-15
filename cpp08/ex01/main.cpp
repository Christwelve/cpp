/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:24:41 by christianme       #+#    #+#             */
/*   Updated: 2024/01/15 21:47:41 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

int main() {
    try {
        srand(time(0));
        Span sp = Span(1000);
        for (int i = 0; i < 10; ++i) {
            int num = rand() % 1000 + 1;
            sp.addNumber(num);
            std::cout << num << std::endl;
        }
        std::cout << "Shortest span:    " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:     " << sp.longestSpan() << std::endl;

        Span test = Span(5);
        int nums[] = {1, 2, 3, 4, 5};
        int *end = nums + sizeof(nums) / sizeof(int);
        std::vector<int> vec(nums, end);
        test.addNumber(vec.begin(), vec.end());

        std::cout << "Shortest span:    " << test.shortestSpan() << std::endl;
        std::cout << "Longest span:     " << test.longestSpan() << std::endl;

    } catch (std::runtime_error &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return (0);
    }
}
