/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:54:39 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 19:39:10 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), target_() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &shrubberyCreationForm)
    : AForm(shrubberyCreationForm), target_(shrubberyCreationForm.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &shrubberyCreationForm) {
    if (this != &shrubberyCreationForm) {
        AForm::operator=(shrubberyCreationForm);
        const_cast<std::string &>(target_) = shrubberyCreationForm.target_;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade()) {
        throw GradeTooLowException();
    }
    std::ofstream ofs((target_ + "_shrubbery").c_str());
    if (!ofs.is_open()) throw std::runtime_error("File open failed");

    ofs << "    1           1    " << std::endl;
    ofs << "   222         222   " << std::endl;
    ofs << "  33333       33333  " << std::endl;
    ofs << " 4444444     4444444 " << std::endl;
    ofs << "555555555   555555555" << std::endl;
    ofs << "    |           |    " << std::endl;
    ofs.close();
}

// AForm *ShrubberyCreationForm::createForm(const std::string &target) {
//     return (new ShrubberyCreationForm(target));
// }
