/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:16:49 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 13:44:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <map>
#include <string>

class Harl {
   public:
    Harl();
    ~Harl();
    void complain(std::string level);

   private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif
