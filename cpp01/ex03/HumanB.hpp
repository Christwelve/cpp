/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:10:21 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 05:26:09 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string m_name;
        Weapon* m_weapon;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon& weapon);
        void attack();     
        
};

#endif