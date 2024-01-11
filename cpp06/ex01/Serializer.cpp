/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:13:06 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 07:10:58 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) { return; }

Serializer::Serializer(const Serializer &serializer) { *this = serializer; }

Serializer &Serializer::operator=(const Serializer &serializer) {
    static_cast<void>(serializer);
    return (*this);
}

Serializer::~Serializer(void) { return; }

unsigned long Serializer::serialize(Data *ptr) { return (reinterpret_cast<unsigned long>(ptr)); }

Data *Serializer::deserialize(unsigned long raw) { return (reinterpret_cast<Data *>(raw)); }