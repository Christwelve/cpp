/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:07:45 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/16 13:23:24 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

#include "BitcoinExchange.hpp"

int main(int argc, char const **argv) {
    if (argc != 2) {
        std::cout << "Error: Please use ./btc <filename>.txt" << std::endl;
        return (1);
    }
    // Inputfile -> Stream
    // Stream -> Parsing (Validation)
    // if (valid) {
    // Stream -> map (key: timestamp, value: price)
    // }
}