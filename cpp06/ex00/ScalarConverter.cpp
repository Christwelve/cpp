/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:20 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 06:12:53 by cmeng            ###   ########.fr       */
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

    if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf") return (PSEUDO);
    if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff") return (PSEUDO);

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
    if (!p && !fl && !ch && num && sign <= 1) return (INT);
    if (p == 1 && !fl && !ch && num && sign <= 1) return (DOUBLE);
    if (p <= 1 && fl && !ch && num && sign <= 1) return (FLOAT);
    if (str.size() == 1 && isprint(str[0]) && !num)
        return (CHAR);
    else
        return (INVALID);
}

std::string ScalarConverter::decFloat(float f) {
    std::stringstream dec;
    dec << f;
    if (dec.str().find('.') == std::string::npos) dec << ".0";
    dec << "f";
    return (dec.str());
}

std::string ScalarConverter::decDouble(double d) {
    std::stringstream dec;
    dec << d;
    if (dec.str().find('.') == std::string::npos) dec << ".0";
    return (dec.str());
}

// handle edge cases inf, -inf, +inf, nan nanf, inff, -inff, +inff
void ScalarConverter::pseudo(const std::string &str) {
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

void ScalarConverter::toChar(std::istringstream &iss) {
    char c;
    if (!(iss >> c)) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (static_cast<int>(c) < 32 || static_cast<int>(c) > 126) {
        std::cout << "char: Not displayable" << std::endl;
    } else {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
}

void ScalarConverter::toInt(std::istringstream &iss) {
    bool overflow = false;
    int i;

    if (!(iss >> i)) overflow = true;

    if (overflow) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // char
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (i < 32 || i > 126) {
        std::cout << "char: Not displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    }

    // int
    std::cout << "int: " << i << std::endl;

    // float
    std::cout << "float: " << std::fixed << std::setprecision(5) << decFloat(static_cast<float>(i)) << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(5) << decDouble(static_cast<double>(i)) << std::endl;
}

void ScalarConverter::toFloat(std::istringstream &iss) {
    bool overflow = false;
    float f;

    if (!(iss >> f)) overflow = true;

    if (overflow) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // char
    if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (f < 32 || f > 126) {
        std::cout << "char: Not displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    }

    // int
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }

    // float
    std::cout << "float: " << std::fixed << std::setprecision(5) << decFloat(f) << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(5) << decDouble(static_cast<double>(f)) << std::endl;
}

void ScalarConverter::toDouble(std::istringstream &iss) {
    bool overflow = false;
    double d;

    if (!(iss >> d)) overflow = true;

    if (overflow) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // char
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (d < 32 || d > 126) {
        std::cout << "char: Not displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }

    // int
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }

    // float
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(5) << decFloat(static_cast<float>(d)) << std::endl;
    }

    // double
    std::cout << "double: " << std::fixed << std::setprecision(5) << decDouble(d) << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
    type source = parsing(str);
    if (source == INVALID) {
        std::cerr << "Invalid Input" << std::endl;
        return;
    }

    std::istringstream iss;
    if (source == FLOAT) {
        std::string strFloat = str;
        strFloat.erase(strFloat.size() - 1, 1);
        iss.str(strFloat);
    } else {
        iss.str(str);
    }

    // std::cout << source << std::endl;

    switch (source) {
        case CHAR:
            toChar(iss);
            break;
        case INT:
            toInt(iss);
            break;
        case FLOAT:
            toFloat(iss);
            break;
        case DOUBLE:
            toDouble(iss);
            break;
        case PSEUDO:
            pseudo(str);
            break;
        case INVALID:
            break;
    }
}
