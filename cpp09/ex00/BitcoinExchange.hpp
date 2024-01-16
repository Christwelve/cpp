/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:27 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/16 19:56:19 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
    std::map<std::string, float> data_;
    void parseData(std::fstream &file);
    int invalidDate(std::string &date, size_t &i);
    int invalidValue(std::string &value, size_t &i);
};

#endif