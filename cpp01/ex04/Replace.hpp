/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 05:52:04 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 13:42:43 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <fstream>
#include <iostream>
#include <string>

class Replace {
   public:
    Replace(std::string filename, std::string s1, std::string s2);
    ~Replace();
    void replace();

   private:
    std::string filename_;
    std::string s1_;
    std::string s2_;
};

#endif
