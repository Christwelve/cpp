/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:31:28 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 05:35:57 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

class ScalarConverter {
   public:
    ~ScalarConverter();  // Destructor
    static void convert(const std::string &str);

   private:
    ScalarConverter(void);                                               // Default Constructor
    ScalarConverter(const ScalarConverter &scalarConverter);             // Copy Constructor
    ScalarConverter &operator=(const ScalarConverter &scalarConverter);  // Assignation Operator

    static type parsing(const std::string &str);
    static void pseudo(const std::string &str);
    static void toChar(std::istringstream &iss);
    static void toInt(std::istringstream &iss);
    static void toFloat(std::istringstream &iss);
    static void toDouble(std::istringstream &iss);
    static std::string decFloat(float f);
    static std::string decDouble(double d);
};

#endif