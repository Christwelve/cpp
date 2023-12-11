/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:10:21 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 12:51:20 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
   public:
    HumanB(std::string name);
    ~HumanB(void);
    void setWeapon(Weapon &weapon);
    void attack();

   private:
    std::string name_;
    Weapon *weapon_;
};

#endif