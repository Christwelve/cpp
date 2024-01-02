/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:58:06 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 20:06:18 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
   public:
    Intern(void);                             // Default Constructor
    Intern(const Intern &intern);             // Copy Constructor
    Intern &operator=(const Intern &intern);  // Assignation Operator
    ~Intern();                                // Destructor

    AForm *makeForm(const std::string &name, const std::string &target);

   private:
};

#endif