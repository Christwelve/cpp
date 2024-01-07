/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:31:28 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/07 18:24:05 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum type { CHAR, INT, FLOAT, DOUBLE, INVALID };

class ScalarConverter {
   public:
    ~ScalarConverter();  // Destructor
    static void convert(const std::string &str);

   private:
    ScalarConverter(void);                                               // Default Constructor
    ScalarConverter(const ScalarConverter &scalarConverter);             // Copy Constructor
    ScalarConverter &operator=(const ScalarConverter &scalarConverter);  // Assignation Operator

    static void stoc(std::istringstream &iss);
    static void stoi(std::istringstream &iss);
    static void stof(std::istringstream &iss);
    static void stod(std::istringstream &iss);
    static type parsing(const std::string &str);
};

#endif