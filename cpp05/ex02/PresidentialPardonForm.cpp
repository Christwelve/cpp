/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:10:52 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 18:20:27 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(), target_() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &presidentialPardonForm)
    : AForm(presidentialPardonForm), target_(presidentialPardonForm.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &presidentialPardonForm) {
    if (this != &presidentialPardonForm) {
        AForm::operator=(presidentialPardonForm);
        const_cast<std::string &>(target_) = presidentialPardonForm.target_;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade()) {
        throw GradeTooLowException();
    }

    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}