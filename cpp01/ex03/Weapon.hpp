/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:15:11 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 16:14:51 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
   public:
    Weapon(std::string type);
    ~Weapon();
    void setType(std::string type);
    const std::string& getType() const;

   private:
    std::string type_;
};

#endif