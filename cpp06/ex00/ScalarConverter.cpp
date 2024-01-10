/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:20 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/10 20:43:44 by cmeng            ###   ########.fr       */
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
    std::cout << "float: " << std::setprecision(5) << static_cast<float>(i) << ".0f" << std::endl;

    // double
    std::cout << "double: " << std::setprecision(5) << static_cast<double>(i) << ".0" << std::endl;
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

    int nDec = static_cast<int>(f);
    // float
    if (f != nDec) {
        std::cout << "float: " << std::setprecision(5) << f << "f" << std::endl;
    } else {
        std::cout << "float: " << std::setprecision(5) << f << ".0f" << std::endl;
    }

    // double
    if (f != nDec) {
        std::cout << "double: " << std::setprecision(5) << static_cast<double>(f) << std::endl;
    } else {
        std::cout << "double: " << std::setprecision(5) << static_cast<double>(f) << ".0" << std::endl;
    }
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

    int nDec = static_cast<int>(d);
    // float
    if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        if (d != nDec) {
            std::cout << "float: " << std::setprecision(5) << d << "f" << std::endl;
        } else {
            std::cout << "float: " << std::setprecision(5) << d << ".0f" << std::endl;
        }
    }

    // double
    if (d != nDec) {
        std::cout << "double: " << std::setprecision(5) << static_cast<double>(d) << std::endl;
    } else {
        std::cout << "double: " << std::setprecision(5) << static_cast<double>(d) << ".0" << std::endl;
    }
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

    std::cout << source << std::endl;

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

// // handle single character
// if (str.size() == 1 && (source == CHAR)) {
//     char c = str[0];
//     std::cout << "char: '" << c << "'" << std::endl;
//     std::cout << "int: " << static_cast<int>(c) << std::endl;
//     std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
//     std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
//     return;
// }

// std::istringstream iss;
// source == FLOAT ? iss.str(strFloat) : iss.str(str);
// double conv;
// if (!(iss >> conv)) {
//     std::cout << "char: impossible" << std::endl;
//     std::cout << "int: impossible" << std::endl;
//     std::cout << "float: impossible" << std::endl;
//     std::cout << "double: impossible" << std::endl;
//     return;
// }

// // handle char
// if (static_cast<int>(conv) < 32 || static_cast<int>(conv) > 126) {
//     std::cout << "char: Not displayable" << std::endl;
// } else {
//     std::cout << "char: '" << static_cast<char>(conv) << "'" << std::endl;
// }

// // handle int
// if (conv < std::numeric_limits<int>::min() || conv > std::numeric_limits<int>::max()) {
//     std::cout << "int: impossible" << std::endl;
// } else {
//     std::cout << "int: " << static_cast<int>(conv) << std::endl;
// }

// // handle float
// float dec = static_cast<float>(conv);

// if (conv < -std::numeric_limits<float>::max() || conv > std::numeric_limits<float>::max()) {
//     std::cout << "float: impossible" << std::endl;
// } else {
//     if (dec != static_cast<int>(dec)) {
//         std::cout << "float: " << std::setprecision(10) << static_cast<float>(conv) << "f" << std::endl;
//     } else {
//         std::cout << "float: " << std::setprecision(10) << static_cast<float>(conv) << ".0f" << std::endl;
//     }
// }

// // handle double
// if (dec != static_cast<int>(dec)) {
//     std::cout << "double: " << std::setprecision(10) << conv << std::endl;
// } else {
//     std::cout << "double: " << std::setprecision(10) << conv << ".0" << std::endl;
// }

// void ScalarConverter::toInt(std::istringstream &iss) {
//     bool overflow = false;
//     int i;

//     if (!(iss >> i)) overflow = true;

//     if (overflow) {
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: impossible" << std::endl;
//         std::cout << "double: impossible" << std::endl;
//         return;
//     }

//     // char
//     if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
//         std::cout << "char: impossible" << std::endl;
//     } else if (i < 32 || i > 126) {
//         std::cout << "char: Not displayable" << std::endl;
//     } else {
//         std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
//     }

//     // int
//     if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
//         std::cout << "int: impossible" << i << std::endl;
//     } else {
//         std::cout << "int: " << i << std::endl;
//     }

//     // float
//     float f = static_cast<float>(i);
//     if (f != i) {
//         std::cout << "float: " << std::setprecision(5) << f << "f" << std::endl;
//     } else {
//         std::cout << "float: " << std::setprecision(5) << f << ".0f" << std::endl;
//     }

//     // double
//     double d = static_cast<double>(i);
//     if (d != i) {
//         std::cout << "double: " << std::setprecision(5) << d << std::endl;
//     } else {
//         std::cout << "double: " << std::setprecision(5) << d << ".0" << std::endl;
//     }
// }