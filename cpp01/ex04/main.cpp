/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 05:49:26 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 09:12:16 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Wrong syntax: ./Replace filename s1 s2" << std::endl;
        return (1);
    }

    Replace Test(argv[1], argv[2], argv[3]);
    Test.replace();
    return (0);
}