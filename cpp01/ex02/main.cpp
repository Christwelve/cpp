/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:52:48 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 13:40:52 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of str:              " << &str << std::endl;
    std::cout << "The memory address held by stringPTR:   " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF:   " << &stringREF << std::endl;
    std::cout << "======================================================" << std::endl;

    std::cout << "The value address of str:              " << str << std::endl;
    std::cout << "The value pointed to by stringPTR:     " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF:     " << stringREF << std::endl;

    return (0);
}
