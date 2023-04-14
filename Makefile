# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 14:53:17 by aroussea          #+#    #+#              #
#    Updated: 2023/03/13 18:34:16 by aroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGSMLX = -framework Cocoa -framework OpenGL -framework IOKit
NAME = fdf
LIBMLX	:= ./MLX42
SOURCE = src/main.c \
		 src/trace_ligne.c \
		 src/fdf_init.c \
		 src/map_parsing.c \
		 src/free.c \
		 src/draw.c \
		 src/projection.c \
		 src/event_handler.c \

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm libft/libft.a
OBJS = $(SOURCE:.c=.o)

all: lib libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

lib:
	@make -C libft/

%.o : %.c 
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FLAGSMLX) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	$(info Tous propre!)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx