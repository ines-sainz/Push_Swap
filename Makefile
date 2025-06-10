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

# Name of the final executable for the main program
NAME        = push_swap

# Name of the final executable for the bonus (checker)
NAME_BONUS  = checker

# Compiler to use
CC          = gcc

# Compiler flags: warnings, debugging info (optional: sanitize for leaks)
CFLAGS      = -Wall -Werror -Wextra -g3 #-fsanitize=leak

# Path to the compiled libft library
LIBFT       = ./libft/libft.a

# Source files for the main program
SRCS        = main.c \
              ft_parse.c \
              ft_stack.c \
              ft_moves.c \
              ft_moves2.c \
              ft_small_ordenate.c \
              ft_order_index.c \
              ft_push_swap.c \
              ft_sort.c

# Source files for the bonus program (checker)
SRCS_BONUS  = src_bonus/main_bonus.c \
              src_bonus/ft_parse_bonus.c \
              src_bonus/ft_stack_bonus.c \
              src_bonus/ft_moves_bonus.c \
              src_bonus/ft_moves2_bonus.c \
              src_bonus/ft_order_index_bonus.c \
              src_bonus/ft_push_swap_bonus.c

# Object files generated from main sources
OBJS        = $(SRCS:.c=.o)

# Object files generated from bonus sources
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

# Default target: builds the main executable
all: $(NAME)

# Rule to link object files and produce the main executable
$(NAME): $(OBJS)
	$(MAKE) -C libft                         # Build libft first
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $(NAME)  # Link everything

# Target to build the bonus executable
bonus: $(NAME_BONUS)

# Rule to link object files and produce the bonus executable
$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C libft                              # Build libft first
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L libft -lft -o $(NAME_BONUS)  # Link

# Removes object files (main and bonus)
clean:
	$(MAKE) -C libft clean     # Clean libft object files
	rm -f  $(OBJS)             # Remove main object files
	rm -f  $(OBJS_BONUS)       # Remove bonus object files

# Cleans all generated files including executables
fclean: clean
	$(MAKE) -C libft fclean    # Also remove libft.a
	rm -f  $(NAME)             # Remove main executable
	rm -f  $(NAME_BONUS)       # Remove bonus executable

# Rebuild everything from scratch
re: fclean all

# Declare non-file targets to prevent make from getting confused
.PHONY: clean fclean re all bonus
