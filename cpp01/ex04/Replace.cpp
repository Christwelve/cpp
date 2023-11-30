/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 06:00:29 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 06:25:02 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) 
    : m_filename(filename), m_s1(s1), m_s2(s2) 
{
    return;
};

Replace::~Replace()
{
    return;
}    

void Replace::replace()
{
    std::fstream fs;
    
}

