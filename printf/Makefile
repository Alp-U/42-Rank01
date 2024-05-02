# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: autku <autku@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 21:35:01 by autku             #+#    #+#              #
#    Updated: 2024/04/24 22:22:13 by autku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

ODIR = object_files

FUNCTIONS = ft_print_char.c ft_print_digit.c ft_printf.c ft_print_format.c ft_print_hexc.c ft_print_ptr.c ft_print_str.c

CFLAGS = -Wextra -Wall -Werror

OBJS = $(FUNCTIONS:.c=.o)

all: $(NAME) $(ODIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(ODIR):
	mkdir -p $(ODIR)
	mv *.o $(ODIR)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
