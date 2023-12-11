# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 21:59:29 by cmeng             #+#    #+#              #
#    Updated: 2023/12/11 13:53:55 by cmeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PhoneBook

CC        = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 
#CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address

HEADERS = Contact.hpp PhoneBook.hpp
SRCS    = main.cpp Contact.cpp PhoneBook.cpp 

# ---------------------------------------------------------------------------- #

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
	@$(CC) $(CPPFLAGS) $(SRCS) -o $@

clean :
	$(RM) $(NAME)

re : clean all

.PHONY : all clean re