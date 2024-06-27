# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:49:45 by isainz-r          #+#    #+#              #
#    Updated: 2024/05/14 10:08:15 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -fsanitize=leak -g3
LIBFT   = ./libft/libft.a

SRCS =	main.c \
		ft_parse.c \
		ft_stack.c \
		ft_moves.c \
		ft_moves2.c \
		ft_libft2.c \
		ft_small_ordenate.c \
		ft_order_index.c \
		ft_push_swap.c \
		ft_sort.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f  $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f  $(NAME)

re: fclean all

.PHONY: clean fclean re all
