/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:18 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/17 21:24:13 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) { return; }

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    getDB();
    getInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange) {
    *this = bitcoinExchange;
    return;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
    this->db_ = bitcoinExchange.db_;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) { return; }

// ---------------------------- Parsing -----------------------------------------//

int BitcoinExchange::invalidDate(Date &date, size_t &i) {
    bool leapYear = (date.year % 4 == 0);
    int months[] = {31, leapYear ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((date.year < 2009 && date.month == 1 && date.day < 3) || date.year < 2009) {
        std::cout << RED << "Error: " << CLEAR << "Bitcoin Genesis Block was created on the 3rd of January 2009 😯" << std::endl;
        return (1);
    }
    if (date.year > 2024) {
        std::cout << RED << "Error: " << CLEAR << "Invalid date format: Invalid year @line: " << i << std::endl;
        return (1);
    }
    if (date.month < 1 || date.month > 12) {
        std::cout << RED << "Error: " << CLEAR << "Invalid date format: Invalid month @line: " << i << std::endl;
        return (1);
    }
    if (date.day < 1 || date.day > months[date.month - 1]) {
        std::cout << RED << "Error: " << CLEAR << "Invalid date format: Invalid day @line: " << i << std::endl;
        return (1);
    }
    return (0);
}

int BitcoinExchange::invalidAmount(float &amount, size_t &i) {
    if (amount < 0) {
        std::cout << RED << "Error: " << CLEAR << "Invalid amount format: Negative amount @line: " << i << std::endl;
        return (1);
    }
    if (amount > 1000) {
        std::cout << RED << "Error: " << CLEAR << "Invalid amount format: Amount too high @line: " << i << std::endl;
        return (1);
    }
    return (0);
}

void BitcoinExchange::getDB(void) {
    std::fstream csvFile(DB_PATH);
    if (!csvFile.is_open()) {
        std::cout << "Error: Cannot open csv file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        if (line == "date,exchange_rate") continue;
        size_t pos = line.find(",");
        std::string dateStr;
        std::string priceStr;
        if (pos != std::string::npos) {
            dateStr = line.substr(0, pos);
            priceStr = line.substr(pos + 1, line.length() - pos);

            int year;
            int month;
            int day;
            float price;
            Date date;

            char dash;
            std::stringstream(dateStr) >> year >> dash >> month >> dash >> day;
            std::stringstream(priceStr) >> price;
            date.year = year;
            date.month = month;
            date.day = day;

            db_[date] = price;
        }

        // std::cout << "date: " << date.year << date.month << date.day std::endl;
        // std::cout << "price: " << price << std::endl;
    }
    // for (std::map<Date, float>::const_iterator it = db_.begin(); it != db_.end(); ++it) {
    //     const Date &date = it->first;
    //     float price = it->second;
    //     std::cout << "Date: " << date.year << "-" << date.month << "-" << date.day << ", Price: " << price << std::endl;
    // }
}

void BitcoinExchange::getInput(const std::string &filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Cannot open input file" << std::endl;
        return;
    }
    std::string line;
    size_t i = 1;
    while (std::getline(file, line)) {
        if (line == "date | value") {
            ++i;
            continue;
        }
        size_t pos = line.find("|");
        std::string dateStr;
        std::string amountStr;
        if (pos != std::string::npos) {
            dateStr = line.substr(0, pos - 1);
            amountStr = line.substr(pos + 2, line.length() - pos);

            int year;
            int month;
            int day;
            float amount;
            char dash;
            std::stringstream(dateStr) >> year >> dash >> month >> dash >> day;
            std::stringstream(amountStr) >> amount;

            Date date;
            date.year = year;
            date.month = month;
            date.day = day;

            if (!invalidDate(date, i) && !invalidAmount(amount, i)) {
                // std::cout << "Source:   " << line << std::endl;
                // std::cout << "Date:     " << date << std::endl;
                // std::cout << "Value:    " << amount << std::endl;
                // std::cout << "-------------------------" << std::endl;
                // Calculate price() {
                // open .csv -> db.map()
                // use string stream to get dbDate and dbPrice and compare it to date of db.map()
                // take date and
                std::cout << "calcutate price" << std::endl;
            }
        } else {
            std::cerr << "Error: Invalid format, missing '|' delimiter in line " << i << std::endl;
            return;
        }
        ++i;
    }
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