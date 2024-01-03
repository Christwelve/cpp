/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:03 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 18:07:06 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm(void);                       // Default Constructor
    RobotomyRequestForm(const std::string &target);  // Constructor
    RobotomyRequestForm(
        const RobotomyRequestForm &robotomyRequestForm);  // Copy Constructor
    RobotomyRequestForm &operator=(
        const RobotomyRequestForm &robotomyRequestForm);  // Assignation Operator
    ~RobotomyRequestForm();                               // Destructor

    void execute(const Bureaucrat &executor) const;

   private:
    const std::string target_;
};

#endif