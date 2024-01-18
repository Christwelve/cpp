/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:00:29 by christianme       #+#    #+#             */
/*   Updated: 2024/01/18 16:58:41 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

class RPN {
	public:
	RPN(void);
	RPN(const std::string &str);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	
	bool invalidString(const std::string &str);
	void calculate(const std::string &str);

	private:
	std::stack<int> stack_;

};

#endif