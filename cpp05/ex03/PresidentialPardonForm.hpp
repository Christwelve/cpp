/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:10:07 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 19:39:10 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm(void);                       // Default Constructor
    PresidentialPardonForm(const std::string &target);  // Constructor
    PresidentialPardonForm(
        const PresidentialPardonForm &presidentialPardonForm);  // Copy Constructor
    PresidentialPardonForm &operator=(
        const PresidentialPardonForm &presidentialPardonForm);  // Assignation Operator
    ~PresidentialPardonForm();                                  // Destructor

    void execute(const Bureaucrat &executor) const;

    // AForm *createForm(const std::string &target);

   private:
    const std::string target_;
};

#endif