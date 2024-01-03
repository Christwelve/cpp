/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:06:06 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/02 18:05:05 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

#include "AForm.hpp"

class Bureaucrat {
   public:
    Bureaucrat(void);                                     // Default Constructor
    Bureaucrat(const std::string &name, int grade);       // Constructor
    Bureaucrat(const Bureaucrat &bureaucrat);             // Copy Constructor
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);  // Assignation Operator
    ~Bureaucrat();                                        // Destructor

    class GradeTooHighException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    const std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(AForm &form);
    void executeForm(AForm const &form);

   private:
    const std::string name_;
    int grade_;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif