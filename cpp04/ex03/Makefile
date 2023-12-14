# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 21:59:29 by cmeng             #+#    #+#              #
#    Updated: 2023/12/13 15:23:14 by cmeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  Interface

CC        = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 
# SANFLAG	  = -L../../../../../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../../../../../LeakSanitize

HEADERS = Interface.hpp
SRCS    = main.cpp Interface.cpp

# ---------------------------------------------------------------------------- #

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $@

clean :
	$(RM) $(NAME)

re : clean all

.PHONY : all clean re