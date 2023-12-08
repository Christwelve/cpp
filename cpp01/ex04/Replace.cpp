/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 06:00:29 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:43:23 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
    : filename_(filename), s1_(s1), s2_(s2) {
    return;
};

Replace::~Replace() { return; }

void Replace::replace() { std::fstream fs; }
