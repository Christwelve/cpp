/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:33:14 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/13 19:55:20 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int main() {
    Array<int> intArray(10);
    std::cout << "Original array size:  " << intArray.size() << std::endl;
    Array<int> copiedArray = intArray;
    std::cout << "Copied array size:    " << copiedArray.size() << std::endl;

    Array<std::string> strArray(5);
    std::cout << "Original string array size:  " << strArray.size() << std::endl;
    Array<std::string> copiedStrArray = strArray;
    std::cout << "Copied string array size:    " << copiedStrArray.size() << std::endl;

    return (0);
}