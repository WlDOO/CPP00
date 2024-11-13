# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh <najeuneh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 14:43:27 by najeuneh          #+#    #+#              #
#    Updated: 2024/11/13 15:28:20 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp\

NAME = account

INCLUDE = -I Account.hpp \

MY_OBJECTS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	@$(CC) $(CPP_FLAGS) $(INCLUDE) $(MY_OBJECTS) -o $(NAME)

clean:
	@${RM} ${MY_OBJECTS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all