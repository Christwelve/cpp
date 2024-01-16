/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:10:27 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/16 13:10:47 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>

class BitcoinExchange {
   public:
    BitcoinExchange(void);                                               // Default Constructor
    BitcoinExchange(const std::string &str);                             // Constructor
    BitcoinExchange(const BitcoinExchange &bitcoinExchange);             // Copy Constructor
    BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);  // Assignation Operator
    ~BitcoinExchange();                                                  // Destructor

   private:
};

#endif