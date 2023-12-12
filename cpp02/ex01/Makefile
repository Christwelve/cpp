# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 21:59:29 by cmeng             #+#    #+#              #
#    Updated: 2023/12/12 08:47:12 by cmeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Useful

CC        = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 
# CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address

HEADERS = Fixed.hpp
SRCS    = main.cpp Fixed.cpp 

# ---------------------------------------------------------------------------- #

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $@

clean :
	$(RM) $(NAME)

re : clean all

.PHONY : all clean re