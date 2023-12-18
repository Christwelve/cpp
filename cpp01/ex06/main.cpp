/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:13:46 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 13:44:42 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid syntax: ./harlFilter <type of filter>" << std::endl;
        return (1);
    }

    Harl harl;
    harl.complain(argv[1]);
    return (0);
}
