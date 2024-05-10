# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: autku <autku@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 11:08:46 by autku             #+#    #+#              #
#    Updated: 2024/05/10 11:11:55 by autku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

CFLAGS = -Wextra -Wall -Werror

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
