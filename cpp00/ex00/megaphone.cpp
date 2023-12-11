/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:56:45 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 13:13:11 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            std::string str(argv[i]);
            for (size_t i = 0; i < str.length(); i++) {
                str[i] = std::toupper(str[i]);
            }
            std::cout << str;
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return (0);
}