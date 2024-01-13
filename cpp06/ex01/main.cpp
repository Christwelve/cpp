/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:15:41 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/13 16:14:35 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main() {
    Data data = {42, "Heilbronn"};
    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(raw);

    if (ptr == deserialized) {
        std::cout << ptr << std::endl;
        std::cout << deserialized << std::endl;
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << ptr << std::endl;
        std::cout << deserialized << std::endl;
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}