#include "Bureaucrat.hpp"

#include <iostream>

#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : name_("default"), grade_(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : name_(bureaucrat.name_), grade_(bureaucrat.grade_) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
        grade_ = bureaucrat.grade_;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

// ---------------- Exceptions ---------------- //

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

// ---------------- Member functions ---------------- //

const std::string Bureaucrat::getName(void) const { return (name_); }

int Bureaucrat::getGrade(void) const { return (grade_); }

void Bureaucrat::incrementGrade(void) {
    if (grade_ == 1)
        throw GradeTooHighException();
    else
        grade_--;
}

void Bureaucrat::decrementGrade(void) {
    if (grade_ == 150)
        throw GradeTooLowException();
    else
        grade_++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signs " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name_ << " cannot sign " << form.getName() << " because " << e.what()
                  << std::endl;
    }
}

// ---------------- Overloaders ---------------- //

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}
