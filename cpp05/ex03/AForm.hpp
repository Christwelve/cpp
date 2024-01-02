/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:57:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/31 14:42:27 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
class Bureaucrat;  // Forward declaration (circular dependency)

class AForm {
   public:
    AForm(void);                                                  // Default Constructor
    AForm(const std::string &str, int signGrade, int execGrade);  // Constructor
    AForm(const AForm &form);                                     // Copy Constructor
    AForm &operator=(const AForm &form);                          // Assignation Operator
    virtual ~AForm();                                             // Destructor

    class GradeTooHighException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    const std::string getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executor) const = 0;

   private:
    const std::string name_;
    bool isSigned_;
    const int signGrade_;
    const int execGrade_;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif