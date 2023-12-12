/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 07:59:54 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/12 08:30:37 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

   private:
    int value_;
    static const int fraction_ = 8;
};

#endif