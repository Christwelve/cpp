/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:18 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/19 20:19:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <iomanip>
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
    bool leapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
    int months[] = {31, leapYear ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.month < 1 || date.month > 12) {
        std::cout << RED << "Error: " << CLEAR << "Invalid date format: @line: " << i << std::endl;
        return (1);
    }
    if (date.day < 1 || date.day > months[date.month - 1]) {
        std::cout << RED << "Error: " << CLEAR << "Invalid date format: @line: " << i << std::endl;
        return (1);
    }
    if ((date.year < 2009 && date.month == 1 && date.day < 3) || date.year < 2009) {
        std::cout << RED << "Error: " << CLEAR << "Bitcoin Genesis Block was created on the 3rd of January 2009 😯" << std::endl;
        return (1);
    }
    if (date.year > 2024) {
        std::cout << RED << "Error: " << CLEAR << "Invalid date format: @line: " << i << std::endl;
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
    }
    csvFile.close();
}

void BitcoinExchange::getInput(const std::string &filename) {
    std::fstream file(filename.c_str());
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
            dateStr = line.substr(0, pos);
            amountStr = line.substr(pos + 1, line.length() - pos);

            int year;
            int month;
            int day;
            float amount;
            char dash;
            char trash;
            std::stringstream dateStream(dateStr);
            std::stringstream amountStream(amountStr);

            if (!(dateStream >> year) || !(dateStream >> dash) || !(dateStream >> month) || !(dateStream >> dash) || !(dateStream >> day)) {
                std::cerr << RED << "Error: " << CLEAR << "Invalid date format: @line: " << i << std::endl;
                ++i;
                continue;
            }

            if (!(amountStream >> amount)) {
                std::cerr << RED << "Error: " << CLEAR << "Invalid amount: @line: " << i << std::endl;
                ++i;
                continue;
            }

            if (dateStream >> trash || amountStream >> trash) {
                std::cerr << RED << "Error: " << CLEAR << "Invalid date format: @line: " << i << std::endl;
                ++i;
                continue;
            }

            Date date;
            date.year = year;
            date.month = month;
            date.day = day;

            if (!invalidDate(date, i) && !invalidAmount(amount, i)) {
                std::map<Date, float>::const_iterator it = db_.find(date);
                if (it != db_.end()) {
                    std::cout << date.year << dash << std::setw(2) << std::setfill('0') << date.month << dash << std::setw(2) << std::setfill('0')
                              << date.day << " => " << amount << " = " << GREEN << std::fixed << std::setprecision(2) << amount * it->second
                              << "$" CLEAR << std::endl;
                } else {
                    std::map<Date, float>::const_reverse_iterator rit;
                    for (rit = db_.rbegin(); rit != db_.rend(); ++rit) {
                        if (rit->first < date) {
                            std::cout << rit->first.year << dash << std::setw(2) << std::setfill('0') << rit->first.month << dash << std::setw(2)
                                      << std::setfill('0') << rit->first.day << " => " << amount << " = " << GREEN << std::fixed
                                      << std::setprecision(2) << amount * rit->second << "$" CLEAR << std::endl;
                            break;
                        }
                    }
                }
            }
        } else {
            std::cerr << RED << "Error: " << CLEAR << "Invalid format, missing '|' delimiter in line " << i << std::endl;
        }
        ++i;
    }
    file.close();
}
