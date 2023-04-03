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

SRCS = main.c list_operators.c utils.c rules.c move_counter.c \
ft_split.c sorter.c target_values.c rules2.c algorithm.c list_operators2.c \
calculations.c \

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
MAKE = make

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
