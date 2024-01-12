/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:16:07 by christianme       #+#    #+#             */
/*   Updated: 2024/01/12 21:05:19 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int* end = nums + sizeof(nums) / sizeof(int);
    std::vector<int> vec(nums, end);
    std::list<int> lst(nums, end);

    try {
        std::cout << *easyfind(vec, 3) << std::endl;
        std::cout << *easyfind(lst, 3) << std::endl;
        std::cout << *easyfind(vec, 6) << std::endl;
        std::cout << *easyfind(lst, 6) << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}