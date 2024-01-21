/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:33:32 by christianme       #+#    #+#             */
/*   Updated: 2024/01/21 17:20:09 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <exception>
#include <iostream>

RPN::RPN(void) { return; }

RPN::RPN(const std::string &str) {
    this->calculate(str);
    return;
}

RPN::RPN(const RPN &other) {
    if (this != &other) {
        *this = other;
    }
    return;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->stack_ = other.stack_;
    }
    return *this;
}

RPN::~RPN(void) { return; }

bool RPN::isOperator(const char &c) {
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
        return (true);
    else
        return (false);
}

bool RPN::invalidString(const std::string &str) {
    int check = -1;

    for (size_t i = 0; i < str.length(); i++) {
        if ((i % 2 == 0) && ((!isdigit(str[i])) && (!isOperator(str[i])))) return (true);
        if ((i % 2 == 1) && (!(str[i] == ' '))) return (true);
    }

    for (size_t i = 0; i < str.length(); i += 2) {
        if (isdigit(str[i])) check++;
        if (isOperator(str[i])) check--;
        if (check < 0) return (true);
    }
    if (check != 0) return (true);
    return (false);
}

void RPN::calculate(const std::string &str) {
    if (invalidString(str)) {
        std::cout << RED << "Error: " << CLEAR "Invalid String" << std::endl;
        return;

    } else {
        for (size_t i = 0; i < str.length(); i += 2) {
            if (isdigit(str[i])) {
                stack_.push(str[i] - '0');
            } else if (isOperator(str[i])) {
                int num2 = stack_.top();
                stack_.pop();
                int num1 = stack_.top();
                stack_.pop();

                switch (str[i]) {
                    case '+':
                        stack_.push(num1 + num2);
                        break;
                    case '-':
                        stack_.push(num1 - num2);
                        break;
                    case '*':
                        stack_.push(num1 * num2);
                        break;
                    case '/':
                        if (num2 != 0) {
                            stack_.push(num1 / num2);
                            break;

                        } else {
                            std::cout << RED << "Error: " << CLEAR << " Only Chuck Norris can divide by zero! " << std::endl;
                            return;
                        }
                }
                // std::cout << "-> " << stack_.top() << std::endl;
            }
        }
        // std::cout << "Valid!" << std::endl;
        std::cout << stack_.top() << std::endl;
        // std::cout << "Result: " << stack_.top() << std::endl;
        // std::cout << "default stack size: " << stack_.size() << std::endl;
        // stack_.push(1);
        // stack_.push(2);
        // std::cout << " size: " << stack_.size() << std::endl;
    }

    return;
}
