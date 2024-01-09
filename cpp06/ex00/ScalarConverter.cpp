/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:20 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/09 17:05:44 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>
#include <cfloat>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter) { *this = scalarConverter; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter) {
    (void)scalarConverter;
    return (*this);
}
ScalarConverter::~ScalarConverter() {}

type ScalarConverter::parsing(const std::string &str) {
    int p = 0;
    int fl = 0;
    int sign = 0;
    int ch = 0;
    int num = 0;

    if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf") return (DOUBLE);
    if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff") return (FLOAT);

    for (int i = 0; i < static_cast<int>(str.length()); i++) {
        if (str[i] == '.')
            p++;
        else if (str[i] == 'f')
            fl++;
        else if ((str[i] == '-' && i == 0) || (str[i] == '+' && i == 0))
            sign++;
        else if (!isdigit(str[i]))
            ch++;
        else if (isdigit(str[i]))
            num++;
    }
    if (str.size() == 1 && isprint(str[0])) return (CHAR);
    if (!p && !fl && !ch && num && sign <= 1) return (INT);
    if (p == 1 && !fl && !ch && num && sign <= 1) return (DOUBLE);
    if (p == 1 && fl && !ch && num && sign <= 1) return (FLOAT);
    if (!p && !fl && ch && ch == static_cast<int>(str.size()))
        return (CHAR);
    else
        return (INVALID);
}

void ScalarConverter::convert(const std::string &str) {
    type source = parsing(str);
    if (source == INVALID) {
        std::cerr << "Invalid Input" << std::endl;
        return;
    }
    std::string strFloat = str;
    if (source == FLOAT) {
        strFloat.erase(strFloat.size() - 1, 1);
    }

    // handle edge cases inf, -inf, nan nanf, inff, -inff
    if (str == "nan" || str == "inf" || str == "-inf" || str == "nanf" || str == "inff" || str == "-inff" || str == "+inf" || str == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff") {
            std::cout << "float: " << str << std::endl;
            std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
        } else {
            std::cout << "float: " << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
        }
        return;
    }

    // handle single character
    if (str.size() == 1) {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    std::istringstream iss;
    source == FLOAT ? iss.str(strFloat) : iss.str(str);
    double conv;
    if (!(iss >> conv)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // handle char
    if (static_cast<int>(conv) < 32 || static_cast<int>(conv) > 126) {
        std::cout << "char: Not displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(conv) << "'" << std::endl;
    }

    // handle int
    if (conv < std::numeric_limits<int>::min() || conv > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(conv) << std::endl;
    }

    // handle float
    float dec = static_cast<float>(conv);

    if (conv < -std::numeric_limits<float>::max() || conv > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        if (dec != static_cast<int>(dec)) {
            std::cout << "float: " << std::setprecision(10) << static_cast<float>(conv) << "f" << std::endl;
        } else {
            std::cout << "float: " << std::setprecision(10) << static_cast<float>(conv) << ".0f" << std::endl;
        }
    }

    // handle double
    if (dec != static_cast<int>(dec)) {
        std::cout << "double: " << std::setprecision(10) << conv << std::endl;
    } else {
        std::cout << "double: " << std::setprecision(10) << conv << ".0" << std::endl;
    }
}
