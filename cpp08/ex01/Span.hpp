/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:20:55 by christianme       #+#    #+#             */
/*   Updated: 2024/01/12 20:51:25 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>

class Span {
   public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    template <typename IT>
    void addNumber(IT begin, IT end);

   private:
    unsigned int N;
    std::vector<int> numbers;
};

#endif