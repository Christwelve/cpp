/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:20 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/07 20:54:43 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
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

    if (str == "nan" || str == "inf" || str == "-inf") return (DOUBLE);
    if (str == "nanf" || str == "inff" || str == "-inff") return (FLOAT);

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
    if (p == 1 && fl && !ch && num && sign <= 1) return (FLOAT);
    if (!p && !fl && ch && ch == static_cast<int>(str.length()))
        return (CHAR);
    else
        return (INVALID);
}

void ScalarConverter::stoc(std::istringstream &iss) {
    char conv;
    try {
        iss >> conv;
        if (conv < 32 || conv > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << conv << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(conv) << std::endl;
        std::cout << "float: " << static_cast<float>(conv) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(conv) << ".0" << std::endl;
    } catch (std::exception &e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::stoi(std::istringstream &iss) {
    int convInt = 0;
    double convDouble = 0;
    try {
        iss >> convDouble;
        if (convDouble < INT_MIN || convDouble > INT_MAX) {
            throw std::exception();
        }
        convInt = static_cast<int>(convDouble);
        if (convInt < 32 || convInt > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(convInt) << "'" << std::endl;
        }
        std::cout << "int: " << convInt << std::endl;
        std::cout << "float: " << static_cast<float>(convInt) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(convInt) << ".0" << std::endl;
    } catch (std::exception &e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::stof(std::istringstream &iss) {
    float convFloat = 0.0f;
    double convDouble = 0.0;
    try {
        iss >> convDouble;
        if (convDouble != convDouble) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (convDouble == std::numeric_limits<double>::infinity()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        } else if (convDouble == -std::numeric_limits<double>::infinity()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else {
            if (convDouble < FLT_MIN || convDouble > FLT_MAX) {
                throw std::exception();
            }
            convFloat = static_cast<float>(convDouble);
            if (convFloat < 32 || convFloat > 126) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << static_cast<char>(convFloat) << "'" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(convFloat) << std::endl;
            std::cout << "float: " << convFloat << "f" << std::endl;
            std::cout << "double: " << convDouble << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::stod(std::istringstream &iss) {
    double conv = 0.0;
    bool fail = false;

    if (!(iss >> conv)) fail = true;

    if (fail) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } else {
        if (static_cast<int>(conv) < 32 || static_cast<int>(conv) > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: " << static_cast<char>(conv) << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(conv) << std::endl;
        std::cout << "float: " << static_cast<float>(conv) << ".0f" << std::endl;
        std::cout << "double: " << conv << ".0" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str) {
    type source;

    source = parsing(str);
    if (source == INVALID) {
        std::cerr << "Invalid Input" << std::endl;
        return;
    }

    std::cout << source << std::endl;

    std::istringstream iss(str);
    switch (source) {
        case CHAR:
            stoc(iss);
            break;
        case INT:
            stoi(iss);
            break;
        case FLOAT:
            stof(iss);
            break;
        case DOUBLE:
            stod(iss);
            break;
        case INVALID:
            break;
    }
}
