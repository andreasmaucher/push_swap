# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:20:00 by amaucher          #+#    #+#              #
#    Updated: 2022/12/05 15:39:04 by amaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c insertion.c list_operators.c push_swap_utils.c rules.c \
split.c sorter.c \

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
