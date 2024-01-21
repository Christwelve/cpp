/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:00:29 by christianme       #+#    #+#             */
/*   Updated: 2024/01/21 17:05:22 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

class RPN {
   public:
    RPN();
    RPN(const std::string &str);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void calculate(const std::string &str);

   private:
    std::stack<int> stack_;
    bool invalidString(const std::string &str);
    bool isOperator(const char &c);
};

#endif