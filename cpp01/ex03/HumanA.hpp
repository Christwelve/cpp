/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:10:44 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/18 13:41:46 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    void attack();

   private:
    std::string name_;
    Weapon &weapon_;
};

#endif
