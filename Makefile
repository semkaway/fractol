# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvilna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 08:52:44 by kvilna            #+#    #+#              #
#    Updated: 2017/12/21 17:59:22 by kvilna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft/includes

OPENGL_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

LIB = libft.a

SRC = 	main.c \
		validate_and_set.c\
		keys_and_mouse.c\
		color.c\
		system_functions.c\
		fractals.c\
		fractals2.c\
		iterations.c\
		iterations2.c\

OBG = $(SRC:.c=.o)

.PHONY: $(LIB)

all: $(LIB) $(NAME)

$(LIB):
	@make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -pthread -o $@ -c $<

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OPENGL_FLAGS) -I libft/includes -o $(NAME) $(OBG) -L libft/ -lft

clean:
	@rm -f $(OBG) && make -C libft/ clean

fclean: clean
	@rm -f $(NAME) && make -C libft/ fclean

re: fclean all
