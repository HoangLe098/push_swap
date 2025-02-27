# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 17:47:22 by hoale             #+#    #+#              #
#    Updated: 2025/02/27 16:31:01 by hoale            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

PRINTF_INC	= -I ./printf
PRINTF_LIB	= -L ./printf -lftprintf

LIBFT_INC	= -I ./libft
LIBFT_LIB	= -L ./libft -lft

SRC			= main.c \
				init.c \
				lstft.c \
				lstft2.c \
				min_max.c \
				push2b.c \
				push2a.c \
				rot2top.c \
				sort.c \
				stdft1.c \
				stdft2.c
				
OBJ			= $(SRC:.c=.o)
NAME		= push_swap

all: subsystem $(NAME)

subsystem:
	@make -C ./libft all
	@make -C ./printf all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(PRINTF_INC) $(PRINTF_LIB) $(LIBFT_INC) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(PRINTF_INC) $(LIBFT_INC) -c $< -o $@

clean:
	make -C libft/ clean
	make -C printf/ clean
	rm -f $(OBJ)

tidy:	all clean

fclean:	clean
	make -C libft/ fclean
	make -C printf/ fclean
	rm -f $(NAME)

re:	fclean all