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

NAME		= push_swap
NAME_BONUS	= checker
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 #-fsanitize=leak
LIBFT		= ./libft/libft.a

SRCS		= main.c \
			  ft_parse.c \
			  ft_stack.c \
			  ft_moves.c \
			  ft_moves2.c \
			  ft_small_ordenate.c \
			  ft_order_index.c \
			  ft_push_swap.c \
			  ft_sort.c

SRCS_BONUS	= src_bonus/main_bonus.c \
			  src_bonus/ft_parse_bonus.c \
			  src_bonus/ft_stack_bonus.c \
			  src_bonus/ft_moves_bonus.c \
			  src_bonus/ft_moves2_bonus.c \
			  src_bonus/ft_order_index_bonus.c \
			  src_bonus/ft_push_swap_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L libft -lft -o $(NAME_BONUS)

clean:
	$(MAKE) -C libft clean
	rm -f  $(OBJS)
	rm -f  $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f  $(NAME)
	rm -f  $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
