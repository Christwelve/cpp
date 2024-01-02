/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:20:01 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 19:39:10 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(), target_() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
    : AForm(robotomyRequestForm), target_(robotomyRequestForm.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &robotomyRequestForm) {
    if (this != &robotomyRequestForm) {
        AForm::operator=(robotomyRequestForm);
        const_cast<std::string &>(target_) = robotomyRequestForm.target_;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade()) {
        throw GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;
    srand(time(NULL));
    // int i = rand() % 100;
    // std::cout << i << std::endl;
    if ((rand() % 100) % 2) {
        std::cout << target_ << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy of " << target_ << " failed." << std::endl;
    }
}

// AForm *RobotomyRequestForm::createForm(const std::string &target) {
//     return (new RobotomyRequestForm(target));
// }