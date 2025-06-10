# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 17:16:48 by isainz-r          #+#    #+#              #
#    Updated: 2024/02/02 18:42:06 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library file to create
NAME	= libft.a

# Compiler to use
CC		= cc

# Compiler flags: 
# -Wall enables all warnings
# -Werror turns warnings into errors
# -Wextra enables extra warnings
CFLAGS	= -Wall -Werror -Wextra

# Archive tool to create static libraries
AR		= ar

# Archive flags:
# -r inserts/updates files
# -c creates the archive if it doesn't exist
# -s creates an index (for faster linking)
ARFLAGS	= -rcs

CHAR		=	characters/
CONVERT		=	conversions/
FDS			=	file_descriptors/
MEM			=	memory/
STR			=	strings/

# List of source files for the mandatory part
SRCS =	$(CHAR)ft_isalnum.c \
		$(CHAR)ft_isalpha.c \
		$(CHAR)ft_isascii.c \
		$(CHAR)ft_isdigit.c \
		$(CHAR)ft_isprint.c \
		$(CONVERT)ft_atoi.c \
		$(CONVERT)ft_itoa.c \
		$(CONVERT)ft_tolower.c \
		$(CONVERT)ft_toupper.c \
		$(FDS)ft_putchar_fd.c \
		$(FDS)ft_putendl_fd.c \
		$(FDS)ft_putnbr_fd.c \
		$(FDS)ft_putstr_fd.c \
		$(MEM)ft_bzero.c \
		$(MEM)ft_calloc.c \
		$(MEM)ft_memchr.c \
		$(MEM)ft_memcmp.c \
		$(MEM)ft_memcpy.c \
		$(MEM)ft_memmove.c \
		$(MEM)ft_memset.c \
		$(STR)ft_split.c \
		$(STR)ft_strchr.c \
		$(STR)ft_strdup.c \
		$(STR)ft_striteri.c \
		$(STR)ft_strjoin.c \
		$(STR)ft_strlcat.c \
		$(STR)ft_strlcpy.c \
		$(STR)ft_strlen.c \
		$(STR)ft_strmapi.c \
		$(STR)ft_strncmp.c \
		$(STR)ft_strnstr.c \
		$(STR)ft_strrchr.c \
		$(STR)ft_strtrim.c \
		$(STR)ft_substr.c

# Corresponding object files for the mandatory source files
OBJS = $(SRCS:.c=.o)

# Default target: build the library
all: $(NAME)

# Create the library by archiving the compiled object files
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Remove all compiled object files
clean:
	@rm -f $(OBJS)

# Clean everything, including the library file
fclean: clean
	@rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Declare these targets as phony to avoid conflicts with files of the same name
.PHONY: clean fclean re all
