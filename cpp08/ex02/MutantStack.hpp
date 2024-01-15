/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:42:25 by christianme       #+#    #+#             */
/*   Updated: 2024/01/15 14:57:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    MutantStack();
    MutantStack(const MutantStack<T>& other);
    ~MutantStack();

    MutantStack& operator=(const MutantStack<T>& other);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif