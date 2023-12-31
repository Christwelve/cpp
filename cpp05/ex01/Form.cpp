/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:04:57 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/31 14:47:03 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(void) : name_("default"), isSigned_(false), signGrade_(150), execGrade_(150) {}

Form::Form(const std::string &str, int signGrade, int execGrade)
    : name_(str), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade) {}

Form::Form(const Form &form)
    : name_(form.name_),
      isSigned_(form.isSigned_),
      signGrade_(form.signGrade_),
      execGrade_(form.execGrade_) {}

Form &Form::operator=(const Form &form) {
    if (this != &form) {
        isSigned_ = form.isSigned_;
        const_cast<int &>(signGrade_) = form.signGrade_;
        const_cast<int &>(execGrade_) = form.execGrade_;
    }
    return (*this);
}

Form::~Form() {}

// ---------------- Exceptions ---------------- //

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

// ---------------- Member functions ---------------- //

const std::string Form::getName(void) const { return (name_); }

bool Form::getIsSigned(void) const { return (isSigned_); }

int Form::getSignGrade(void) const { return (signGrade_); }

int Form::getExecuteGrade(void) const { return (execGrade_); }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (isSigned_) throw std::logic_error("Form is already signed");
    if (bureaucrat.getGrade() > signGrade_) throw GradeTooLowException();
    isSigned_ = true;
}

// ---------------- Overloaders ---------------- //

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << form.getName() << " form, sign grade " << form.getSignGrade()
        << ", execute grade " << form.getExecuteGrade()
        << ", is signed: " << form.getIsSigned();
    return (out);
}
