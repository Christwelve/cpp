# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 21:59:29 by cmeng             #+#    #+#              #
#    Updated: 2024/01/20 13:45:30 by cmeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  PmergeMe

CC        = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 
# CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address

HEADERS = PmergeMe.hpp Sorting.tpp
SRCS    = main.cpp PmergeMe.cpp 

# ---------------------------------------------------------------------------- #

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $@

clean :
	$(RM) $(NAME)

re : clean all

.PHONY : all clean re