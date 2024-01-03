/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:04:57 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/31 14:47:03 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm(void)
    : name_("default"), isSigned_(false), signGrade_(150), execGrade_(150) {}

AForm::AForm(const std::string &str, int signGrade, int execGrade)
    : name_(str), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade) {}

AForm::AForm(const AForm &form)
    : name_(form.name_),
      isSigned_(form.isSigned_),
      signGrade_(form.signGrade_),
      execGrade_(form.execGrade_) {}

AForm &AForm::operator=(const AForm &form) {
    if (this != &form) {
        isSigned_ = form.isSigned_;
        const_cast<int &>(signGrade_) = form.signGrade_;
        const_cast<int &>(execGrade_) = form.execGrade_;
    }
    return (*this);
}

AForm::~AForm() {}

// ---------------- Exceptions ---------------- //

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed");
}

// ---------------- Member functions ---------------- //

const std::string AForm::getName(void) const { return (name_); }

bool AForm::getIsSigned(void) const { return (isSigned_); }

int AForm::getSignGrade(void) const { return (signGrade_); }

int AForm::getExecuteGrade(void) const { return (execGrade_); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (isSigned_) throw std::logic_error("it's already signed");
    if (bureaucrat.getGrade() > signGrade_) throw GradeTooLowException();
    isSigned_ = true;
}

// ---------------- Overloaders ---------------- //

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << form.getName() << " form, sign grade " << form.getSignGrade()
        << ", execute grade " << form.getExecuteGrade()
        << ", is signed: " << form.getIsSigned();
    return (out);
}
