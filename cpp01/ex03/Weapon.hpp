/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:15:11 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/08 17:40:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
   private:
    std::string type_;

   public:
    Weapon(std::string type);
    ~Weapon(void);
    void setType(std::string type);
    const std::string& getType() const;
};

#endif