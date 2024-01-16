/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:18 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/16 21:58:04 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) { return; }

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Cannot open file" << std::endl;
        return;
    }
    parseData(file);
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange) {
    *this = bitcoinExchange;
    return;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
    this->data_ = bitcoinExchange.data_;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) { return; }

// ---------------------------- Parsing -----------------------------------------//

int BitcoinExchange::invalidDate(std::string &date, size_t &i) {
    std::tm tm = {};
    std::stringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        std::cout << "Error: Invalid date format @line: " << i << std::endl;
        return (1);
    }
    return (0);
}

// int BitcoinExchange::invalidDate(std::string &date, size_t &i) {
//     if ((date.length() != 10)) {
//         std::cout << "Error: Invalid date format: Too long @line: " << i << std::endl;
//         return (1);
//     }
//     if (date[4] != '-' || date[7] != '-') {
//         std::cout << "Error: Invalid date format: Wrong position of '-' @line: " << i << std::endl;
//         return (1);
//     }
//     if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) || !isdigit(date[5]) || !isdigit(date[6]) ||
//         !isdigit(date[8]) || !isdigit(date[9])) {
//         std::cout << "Error: Invalid date format @line: " << i << std::endl;
//         return (1);
//     }
//     if (date[5] > '1' || (date[5] == '1' && date[6] > '2')) {
//         std::cout << "Error: Invalid date format: Wrong month @line: " << i << std::endl;
//         return (1);
//     }
//     if (date[8] > '3' || (date[8] == '3' && date[9] > '1')) {
//         std::cout << "Error: Invalid date format: Wrong day @line: " << i << std::endl;
//         return (1);
//     }
//     return (0);
// }

int BitcoinExchange::invalidValue(std::string &value, size_t &i) {
    std::istringstream iss(value);
    float val;
    char remaining;
    if (!(iss >> val) || iss >> remaining) {
        std::cout << "Error: Invalid value, not a number @line: " << i << std::endl;
        return (1);
    }
    if (val < 0 || val > 1000) {
        std::cout << "Error: Invalid value, out of range @line: " << i << std::endl;
        return (1);
    }
    return (0);
}

void BitcoinExchange::parseData(std::fstream &file) {
    std::string line;
    size_t i = 1;
    while (std::getline(file, line)) {
        size_t pos = line.find("|");
        std::string date;
        std::string value;
        if (pos != std::string::npos) {
            date = line.substr(0, pos - 1);
            value = line.substr(pos + 2, line.length() - pos);

            if (!invalidDate(date, i) && !invalidValue(value, i)) {
                std::cout << "Source:   " << line << std::endl;
                std::cout << "Date:     " << date << std::endl;
                std::cout << "Value:    " << value << std::endl;
                std::cout << "-------------------------" << std::endl;
            }

        } else {
            std::cerr << "Error: Invalid format, missing '|' delimiter in line " << i << std::endl;
            return;
        }

        // std::cout << "Source:   " << line << std::endl;
        // std::cout << "Date:     " << date << std::endl;
        // std::cout << "Value:    " << value << std::endl;
        // std::cout << "-------------------------" << std::endl;

        // std::stringstream ss(line);
        // std::string date;
        // float value;
        // std::getline(ss, date, '|');

        // if (!(ss >> value)) {
        //     std::cerr << "Error: Invalid value!" << std::endl;
        //     return;
        // }

        // // std::string date;
        // // date = line.substr(0, pos);
        // // checkDate(date);

        // // std::stringstream ss(line);
        // // float value;
        // // if (!(ss >> value)) {
        // //     std::cerr << "Error: Invalid value!" << std::endl;
        // //     return;
        // // }
        // std::cout << "Source:   " << line << std::endl;
        // std::cout << std::endl;
        // std::cout << "Date:     " << date << std::endl;
        // std::cout << "Value:    " << value << std::endl;
        // std::cout << "-------------------------" << std::endl;
        // }
        i++;
    }
}

// void BitcoinExchange::parseData(std::fstream &file) {
//     std::string line;
//     int i = 1;
//     while (std::getline(file, line)) {
//         // std::cout << "Source:   " << line << std::endl;
//         // if (isdigit(line[0])) {

//         // size_t pos = line.find("|");
//         // if (pos == std::string::npos) {
//         //     std::cerr << "Error: Invalid format, missing '|' delimiter in line " << i << std::endl;
//         //     return;
//         // }

//         // std::stringstream ss(line);
//         // std::string date;
//         // float value;
//         // std::getline(ss, date, '|');

//         // if (!(ss >> value)) {
//         //     std::cerr << "Error: Invalid value!" << std::endl;
//         //     return;
//         // }

//         // // std::string date;
//         // // date = line.substr(0, pos);
//         // // checkDate(date);

//         // // std::stringstream ss(line);
//         // // float value;
//         // // if (!(ss >> value)) {
//         // //     std::cerr << "Error: Invalid value!" << std::endl;
//         // //     return;
//         // // }
//         // std::cout << "Source:   " << line << std::endl;
//         // std::cout << std::endl;
//         // std::cout << "Date:     " << date << std::endl;
//         // std::cout << "Value:    " << value << std::endl;
//         // std::cout << "-------------------------" << std::endl;
//         // }
//         i++;
//     }
// }