/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 05:52:04 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 06:09:44 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H

#include <iostream>
#include <fstream>
#include <string>

class Replace 
{
    private: 
        std::string m_filename;
        std::string m_s1;
        std::string m_s2;
    public:
        Replace(std::string filename, std::string s1, std::string s2);
        ~Replace();
        void replace();
}

#endif