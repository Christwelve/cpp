/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:27 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/19 14:39:42 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#ifndef DB_PATH
#define DB_PATH "data.csv"
#endif

#define RED "\033[1;31m"
#define CLEAR "\033[0m"
#define GREEN "\033[1;32m"

struct Date {
    int year;
    int month;
    int day;
    bool operator<(const Date &other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    };
};

#include <map>
#include <string>

class BitcoinExchange {
   public:
    BitcoinExchange(void);                                               // Default Constructor
    BitcoinExchange(const std::string &filename);                        // Constructor
    BitcoinExchange(const BitcoinExchange &bitcoinExchange);             // Copy Constructor
    BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);  // Assignation Operator
    ~BitcoinExchange();                                                  // Destructor

   private:
    std::map<Date, float> db_;
    void getInput(const std::string &filename);
    void getDB(void);
    int invalidDate(Date &date, size_t &i);
    int invalidAmount(float &amount, size_t &i);
};

#endif