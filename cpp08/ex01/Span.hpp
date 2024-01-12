/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:20:55 by christianme       #+#    #+#             */
/*   Updated: 2024/01/12 15:25:43 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

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
    template<typename IT>
    void addNumber(IT begin, IT end);
private:
    unsigned int N;
    std::vector<int> numbers;


};


#endif