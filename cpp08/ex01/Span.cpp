/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:21:19 by christianme       #+#    #+#             */
/*   Updated: 2024/01/21 15:35:07 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <climits>
#include <stdexcept>

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw std::runtime_error("Span is full");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers in span");
    }
    std::sort(numbers.begin(), numbers.end());
    int shortest = INT_MAX;
    for (unsigned int i = 0; i < numbers.size() - 1; ++i) {
        shortest = std::min(shortest, numbers[i + 1] - numbers[i]);
    }
    return shortest;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers in span");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

// template <typename IT>
// void Span::addNumber(IT begin, IT end) {
//     while (begin != end) {
//         addNumber(*begin);
//         ++begin;
//     }
// }