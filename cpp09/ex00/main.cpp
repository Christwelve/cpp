/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:07:45 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/21 16:56:49 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char const** argv) {
    if (argc != 2) {
        std::cout << RED << "Error: " << CLEAR << "Please use: ./btc <filename>.txt" << std::endl;
        return (1);
    }
    BitcoinExchange bitcoinExchange(argv[1]);
    return (0);
}