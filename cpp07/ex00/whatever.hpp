/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:21:59 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 08:43:02 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T &a, T &b) {
    if (a < b) {
      return (a);
    } else {
      return (b);  
    }
}

template <typename T>
T max(T &a, T &b) {
    if (a > b) {
      return (a);
    } else {
      return (b);
    }
    
}


#endif