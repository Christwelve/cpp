/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:57:02 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/31 14:42:27 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
class Bureaucrat;  // Forward declaration (circular dependency)

class Form {
   public:
    Form(void);                                                  // Default Constructor
    Form(const std::string &str, int signGrade, int execGrade);  // Constructor
    Form(const Form &form);                                      // Copy Constructor
    Form &operator=(const Form &form);                           // Assignation Operator
    ~Form();                                                     // Destructor

    class GradeTooHighException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char *what() const throw();
    };

    const std::string getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;

    void beSigned(const Bureaucrat &bureaucrat);

   private:
    const std::string name_;
    bool isSigned_;
    const int signGrade_;
    const int execGrade_;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif