/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:33:32 by christianme       #+#    #+#             */
/*   Updated: 2024/01/18 16:58:33 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <exception>

RPN::RPN(void) {
	return ;
}

RPN::RPN(const std::string &str) {
	this->calculate(str);
	return ;
}

RPN::RPN(const RPN &other) {
	*this = other;
	return ;
}

RPN &RPN::operator=(const RPN &other) {
	this->stack_ = other.stack_;
	return *this;
}

RPN::~RPN(void) {
	return ;
}

bool RPN::invalidString(const std::string &str) {

	size_t numbers = 0;
	size_t operators = 0;

	for(size_t i = 0; i < str.length(); i++) {

		// i % 2 == 0 /> ' '
		// i % 2 == 1 /> digit / operator
		// end fo string no space

		// logic in every iteration i += 2
		// count < 0
		if (str[i] == ' ')
			true;
		else if (isdigit(str[i]))
			numbers++;
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))	
			operators++;
		else if (!(str[i] == ' ')) 
			true;	
		
		i++;
		if (i < str.length()) {
			if (!(str[i] == ' ')) {
				true;
			}

		}
	}
	
	std::cout << "numbers: " << numbers << std::endl;
	std::cout << "signs: " << operators << std::endl;
	// if ((numbers - 1) < operators)
	// 	true;
	false;	
}

void RPN::calculate(const std::string &str) {

	std::cout << invalidString(str) << std::endl;
	// if (invalidString(str)) {
	// 	std::cout << RED << "Error: " << CLEAR "Invalid string" << std::endl;
	// 	return;
	// }
	// else {
	// 	std::cout << "Valid!" << std::endl;
	// }

	return;
}

