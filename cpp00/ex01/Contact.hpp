/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:26:58 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 18:42:49 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
   public:
    Contact();
    Contact(std::string firstName, std::string lastName, std::string nickname,
            std::string phoneNumber, std::string darkestSecret);
    ~Contact();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

   private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;
    std::string darkestSecret_;
};

#endif
