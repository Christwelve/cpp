/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 05:52:04 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:47:51 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
#define REPLACE_H

#include <fstream>
#include <iostream>
#include <string>

class Replace {
   private:
    std::string filename_;
    std::string s1_;
    std::string s2_;

   public:
    Replace(std::string filename, std::string s1, std::string s2);
    ~Replace();
    void replace();
};

#endif