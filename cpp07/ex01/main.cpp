/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:48:17 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 08:51:14 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

void print(int const &i) { std::cout << i << " | "; }

int main() {
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    std::cout << std::endl;
    return 0;
}
