/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 04:10:44 by cmeng             #+#    #+#             */
/*   Updated: 2023/11/30 05:25:33 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string m_name;
        Weapon& m_weapon;
    public:
        HumanA(std::string name , Weapon& weapon);
        ~HumanA(void);
        void attack();     
        
};

#endif