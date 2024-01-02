/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:23 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 19:39:09 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
    ShrubberyCreationForm(void);                       // Default Constructor
    ShrubberyCreationForm(const std::string &target);  // Constructor
    ShrubberyCreationForm(
        const ShrubberyCreationForm &shrubberyCreationForm);  // Copy Constructor
    ShrubberyCreationForm &operator=(
        const ShrubberyCreationForm &shrubberyCreationForm);  // Assignation Operator
    ~ShrubberyCreationForm();                                 // Destructor

    void execute(const Bureaucrat &executor) const;

    // AForm *createForm(const std::string &target);

   private:
    const std::string target_;
};

#endif