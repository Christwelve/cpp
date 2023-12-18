# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 21:59:29 by cmeng             #+#    #+#              #
#    Updated: 2023/12/18 13:39:53 by cmeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Violence

CC        = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic
# CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp
SRCS    = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

# ---------------------------------------------------------------------------- #

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $@

clean :
	$(RM) $(NAME)

re : clean all

.PHONY : all clean re